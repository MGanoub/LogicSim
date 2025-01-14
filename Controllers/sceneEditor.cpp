#include "sceneEditor.h"
#include "Core/Circuit/Managers/circuitManager.h"
#include "UI/Widgets/CircuitElement/OutputElements/ledView.h"
#include "UI/Widgets/CircuitElement/elementConnection.h"
#include "UI/Widgets/CircuitElement/elementPort.h"
#include "UI/Widgets/CircuitElement/elementView.h"
#include "UI/mainwindow.h"
#include <QEvent>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsSceneMouseEvent>
#include <QIODevice>
#include <QMimeData>

namespace UI
{

    SceneEditor::SceneEditor(QObject *parent)
        : QObject(parent)
    {
        m_scene = new CustomWidgets::sceneWidget(this);
        m_scene->setBackgroundBrush(QColor("#ffffe6"));
        m_scene->installEventFilter(this);
        auto *window = qobject_cast<MainWindow *>(this->parent());
        window->updateGraphicView(m_scene);

        m_circuitManager = new Core::Circuit::CircuitManager();
    }

    bool SceneEditor::eventFilter(QObject *obj, QEvent *evt)
    {
        if (obj != m_scene)
        {
            return false;
        }
        const auto eventType = evt->type();
        switch (eventType)
        {
        case QEvent::GraphicsSceneMousePress:
        {
            return handleMousePressEvent(evt);
            break;
        }
        case QEvent::GraphicsSceneMouseMove:
        {
            return handleMouseMovementEvent(evt);
            break;
        }
        case QEvent::GraphicsSceneMouseRelease:
        {
            return handleMouseReleaseEvent(evt);
            break;
        }
        case QEvent::GraphicsSceneDrop:
        {
            return handleDropEvent(evt);
            break;
        }

        case QEvent::GraphicsSceneDragMove:
        case QEvent::GraphicsSceneDragEnter:
        {
            return true;
        }
        default:
            break;
        }
        return QObject::eventFilter(obj, evt);
    }

    bool SceneEditor::handleMousePressEvent(QEvent *event)
    {
        auto *mouseEvt = dynamic_cast<QGraphicsSceneMouseEvent *>(event);
        auto mousePos = mouseEvt->scenePos();
        QGraphicsItem *item = getSceneItemAtPos(mousePos);
        if (item == nullptr)
        {
            return true;
        }
        if (isItemAnElementPort(item) && !hasConnectionStarted())
        {
            auto *connection = new UI::CustomWidgets::ElementConnection();
            setConnectionInEdit(connection);

            auto *port = static_cast<UI::CustomWidgets::ElementPort *>(item);
            port->updateBrush();
            connection->setStartPort(port);
            m_scene->addItem(connection);
        }
        return true;
    }

    bool SceneEditor::hasConnectionStarted()
    {
        return m_isWireConnectionInProgress;
    }
    UI::CustomWidgets::ElementConnection *SceneEditor::getConnectionInEdit()
    {
        return m_connection;
    }
    void SceneEditor::setConnectionInEdit(UI::CustomWidgets::ElementConnection *connection)
    {
        m_connection = connection;
        m_isWireConnectionInProgress = true;
    }

    bool SceneEditor::handleMouseMovementEvent(QEvent *event)
    {
        auto *mouseEvt = dynamic_cast<QGraphicsSceneMouseEvent *>(event);
        auto mousePos = mouseEvt->scenePos();

        if (hasConnectionStarted())
        {
            auto *connection = getConnectionInEdit();
            connection->setEndPos(mousePos);
            connection->updatePath();
            connection->update();
        }
        return true;
    }
    bool SceneEditor::handleMouseReleaseEvent(QEvent *event)
    {
        auto *mouseEvt = dynamic_cast<QGraphicsSceneMouseEvent *>(event);
        auto mousePos = mouseEvt->scenePos();

        if (hasConnectionStarted())
        {
            auto *item = getSceneItemAtPos(mousePos);
            if (item->type() != UI::CustomWidgets::ElementPort::GraphicalType)
            {
                removeConnection();
                return true;
            }
            auto *connection = getConnectionInEdit();
            auto *outputPort = connection->getStartPort();
            auto *inputPort = static_cast<UI::CustomWidgets::ElementPort *>(item);
            auto *outputComp = outputPort->getParent();
            auto *inputComp = inputPort->getParent();
            const auto isConnectionMade = m_circuitManager->addConnection(outputComp->getId(), inputComp->getId(), inputPort->getIndex());

            if (!isConnectionMade)
            {
                removeConnection();
                return true;
            }
            connection->makeConnection(inputPort);
            m_connectionsList.append(connection);
            resetConnectionStatus();

            m_circuitManager->update();
            updateElementsInScene();
        }
        return true;
    }

    void SceneEditor::updateElementsInScene()
    {
        const auto outputList = m_circuitManager->getOutputComponentsList();
        for (auto outputElement : outputList)
        {
            auto elementItr = std::find_if(m_circuitElements.begin(), m_circuitElements.end(), [&](UI::CustomWidgets::ElementView *element)
                                           { return (element->getId() == outputElement->getIndentifier()); });
            if (elementItr != m_circuitElements.end())
            {
                (*elementItr)->setOutputState(outputElement->getOutState());
            }
        }
    }

    void SceneEditor::resetConnectionStatus()
    {
        m_connection = nullptr;
        m_isWireConnectionInProgress = false;
    }
    void SceneEditor::removeConnection()
    {
        auto *connection = getConnectionInEdit();
        m_scene->removeItem(connection);
        m_isWireConnectionInProgress = false;
        delete connection;
    }
    bool SceneEditor::handleDropEvent(QEvent *event)
    {
        auto *dragDropevent = dynamic_cast<QGraphicsSceneDragDropEvent *>(event);
        /* Verify if mimetype is compatible. */
        if (!dragDropevent->mimeData()->hasFormat("application/x-dnditemdata"))
        {
            return false;
        }
        /* Extracting mimedata from drop event. */
        QByteArray itemData = dragDropevent->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        QPointF offset;
        qint32 type;
        dataStream >> offset >> type;
        QPointF pos = dragDropevent->scenePos() - offset;
        event->accept();

        auto elementType = (type == 11) ? Core::Circuit::ElementType::LED : Core::Circuit::ElementType::VCC;
        auto elementId = m_circuitManager->addComponent(elementType);
        if (type == 11)
        {
            auto *elementView = new UI::CircuitElements::LEDView(elementId);
            elementView->setPos(pos);
            m_scene->addItem(elementView);
            m_circuitElements.push_back(elementView);
            return true;
        }

        auto *elementView = new UI::CustomWidgets::ElementView(Core::Circuit::ElementType::VCC, 1, elementId);
        QString imageName = ":/inputs/VCC.png";
        elementView->setPixmap(imageName);
        elementView->setPos(pos);
        m_scene->addItem(elementView);
        m_circuitElements.push_back(elementView);
        return true;
    }

    QGraphicsItem *SceneEditor::getSceneItemAtPos(const QPointF PosPoint)
    {
        QRectF areaOfInterestRect(PosPoint - QPointF(4, 4), QSize(9, 9));
        QList<QGraphicsItem *> sceneItems = m_scene->items(areaOfInterestRect.normalized());
        for (QGraphicsItem *item : qAsConst(sceneItems))
        {
            if (item->type() > QGraphicsItem::UserType)
            {
                return item;
            }
        }
        return nullptr;
    }

    bool SceneEditor::isItemAnElementPort(QGraphicsItem *item)
    {
        return item->type() == UI::CustomWidgets::ElementPort::GraphicalType;
    }
}
