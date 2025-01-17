#include "sceneEditor.h"
#include "Core/Circuit/Components/component.h"
#include "Core/Circuit/Managers/circuitManager.h"
#include "UI/disp/Widgets/CircuitElement/elementConnection.h"
#include "UI/disp/Widgets/CircuitElement/elementFactory.h"
#include "UI/disp/Widgets/CircuitElement/elementPort.h"
#include "UI/disp/Widgets/CircuitElement/elementView.h"
#include <QEvent>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsSceneMouseEvent>
#include <QIODevice>
#include <QKeyEvent>
#include <QMimeData>

namespace UI
{

    SceneEditor::SceneEditor(QGraphicsView *graphicsViewWidget, QObject *parent)
        : QObject(parent),
          m_graphicsView(graphicsViewWidget),
          m_currentEventState(EventState::INITIAL)
    {
        m_scene = new CustomWidgets::sceneWidget(this);
        m_scene->setBackgroundBrush(QColor("#ffffe6"));
        m_scene->installEventFilter(this);
        if (m_graphicsView != nullptr)
        {
            m_graphicsView->setScene(m_scene);
        }
        Core::Circuit::CircuitManager::getInstance().addListenser(this);
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
        case QEvent::KeyPress:
        {
            handleKeyPressed(evt);
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

    void SceneEditor::startConnection(QGraphicsItem *item)
    {
        auto *connection = new UI::CircuitElements::ElementConnection();
        setConnectionInEdit(connection);

        auto *port = static_cast<UI::CircuitElements::ElementPort *>(item);
        connection->setStartPort(port);
        m_scene->addItem(connection);
    }

    bool SceneEditor::handleMousePressEvent(QEvent *event)
    {
        auto *mouseEvt = dynamic_cast<QGraphicsSceneMouseEvent *>(event);
        auto mousePos = mouseEvt->scenePos();
        QGraphicsItem *item = getSceneItemAtPos(mousePos);
        if (item == nullptr)
        {
            m_scene->clearSelection();
            m_currentEventState = EventState::INITIAL;
            return true;
        }
        if (isItemAnElementPort(item))
        {
            m_scene->clearSelection();
            m_currentEventState = EventState::CONNECTION_STARTED;
            startConnection(item);
        }
        if (item->type() == UI::CircuitElements::ElementView::GraphicalType ||
            item->type() == UI::CircuitElements::ElementConnection::GraphicalType)
        {
            m_scene->clearSelection();
            item->setSelected(true);
            m_currentEventState = EventState::ELEMENT_SELECTED;
            if (item->type() == UI::CircuitElements::ElementView::GraphicalType)
            {
                auto *element = static_cast<UI::CircuitElements::ElementView *>(item);
                if (element->isPressable())
                {
                    m_pressedElement = element;
                    updateElementState(element, Core::Circuit::State::ON);
                }
                selectElementConnections(item);
            }
        }
        return true;
    }
    void SceneEditor::updateElementState(UI::CircuitElements::ElementView *element, Core::Circuit::State state)
    {
        element->setVisualState(state);
        Core::Circuit::CircuitManager::getInstance().updateInputComponentState(element->getId(), state);
    }

    void SceneEditor::selectElementConnections(QGraphicsItem *item)
    {
        if (item->type() == UI::CircuitElements::ElementView::GraphicalType)
        {
            auto *element = static_cast<UI::CircuitElements::ElementView *>(item);
            for (auto *connection : m_connectionsList)
            {
                if (connection->isConnectedWith(element->getId()))
                {
                    connection->setSelected(true);
                }
            }
        }
    }

    UI::CircuitElements::ElementConnection *SceneEditor::getConnectionInEdit()
    {
        return m_connection;
    }

    void SceneEditor::setConnectionInEdit(UI::CircuitElements::ElementConnection *connection)
    {
        m_connection = connection;
    }

    bool SceneEditor::handleMouseMovementEvent(QEvent *event)
    {
        auto *mouseEvt = dynamic_cast<QGraphicsSceneMouseEvent *>(event);
        auto mousePos = mouseEvt->scenePos();

        if (m_currentEventState == EventState::CONNECTION_STARTED)
        {
            auto *connection = getConnectionInEdit();
            connection->setEndPos(mousePos);
            connection->updatePath();
        }
        else if (m_currentEventState == EventState::ELEMENT_SELECTED)
        {
            bool isElementSelected = false;
            for (auto *item : m_scene->selectedItems())
            {
                if (item->type() == UI::CircuitElements::ElementView::GraphicalType)
                {
                    isElementSelected = true;
                    item->setPos(mousePos);
                }
            }
            if (isElementSelected)
            {
                for (auto *connection : m_connectionsList)
                {
                    connection->updatePath();
                }
            }
        }
        return true;
    }

    bool SceneEditor::handleMouseReleaseEvent(QEvent *event)
    {
        auto *mouseEvt = dynamic_cast<QGraphicsSceneMouseEvent *>(event);
        auto mousePos = mouseEvt->scenePos();

        if (m_currentEventState == EventState::CONNECTION_STARTED)
        {
            auto *item = getSceneItemAtPos(mousePos);
            if (item->type() != UI::CircuitElements::ElementPort::GraphicalType)
            {
                removeConnectionInEdit();
                return true;
            }
            addConnection(item);
            m_currentEventState = EventState::INITIAL;
        }
        else if (m_currentEventState == EventState::ELEMENT_SELECTED)
        {
            updateElementState(m_pressedElement, Core::Circuit::State::OFF);
        }
        return true;
    }

    void SceneEditor::addConnection(QGraphicsItem *item)
    {
        auto *connection = getConnectionInEdit();
        auto *outputPort = connection->getStartPort();
        auto *inputPort = static_cast<UI::CircuitElements::ElementPort *>(item);
        auto *outputComp = outputPort->getParent();
        auto *inputComp = inputPort->getParent();
        const auto isConnectionMade = Core::Circuit::CircuitManager::getInstance().addConnection(outputComp->getId(), outputPort->getIndex(), inputComp->getId(), inputPort->getIndex());

        if (!isConnectionMade)
        {
            removeConnectionInEdit();
            return;
        }
        connection->makeConnection(inputPort);
        m_connectionsList.append(connection);
        m_connection = nullptr;
    }

    void SceneEditor::circuitChanged()
    {
        const auto componentsList = Core::Circuit::CircuitManager::getInstance().getComponentsList();
        for (auto &component : componentsList)
        {
            auto elementItr = std::find_if(m_circuitElements.begin(), m_circuitElements.end(), [&](UI::CircuitElements::ElementView *element)
                                           { return (element->getId() == component->getIndentifier()); });
            if (elementItr != m_circuitElements.end())
            {
                (*elementItr)->setState(component->getState());
                (*elementItr)->update();
            }
        }
    }

    void SceneEditor::resetConnectionStatus()
    {
        m_connection = nullptr;
    }
    void SceneEditor::removeConnectionInEdit()
    {
        auto *connection = getConnectionInEdit();
        m_scene->removeItem(connection);
        delete connection;
    }

    bool SceneEditor::handleKeyPressed(QEvent *event)
    {

        auto *keyPressedEvent = dynamic_cast<QKeyEvent *>(event);
        if (keyPressedEvent->key() == Qt::Key_Delete && m_currentEventState == EventState::ELEMENT_SELECTED)
        {
            for (auto *item : m_scene->selectedItems())
            {
                if (item->type() == UI::CircuitElements::ElementConnection::GraphicalType)
                {
                    auto *connection = static_cast<UI::CircuitElements::ElementConnection *>(item);
                    removeConnection(connection);
                }
            }
            for (auto *item : m_scene->selectedItems())
            {
                if (item->type() == UI::CircuitElements::ElementView::GraphicalType)
                {
                    auto *element = static_cast<UI::CircuitElements::ElementView *>(item);
                    removeElement(element);
                }
            }
        }
        m_currentEventState = EventState::INITIAL;
        return true;
    }
    void SceneEditor::removeConnection(UI::CircuitElements::ElementConnection *connection)
    {
        auto *startPort = connection->getStartPort();
        auto *endPort = connection->getEndPort();
        const auto firstPortParent = startPort->getParent();
        const auto secondPortParent = endPort->getParent();
        bool isConnectionRemoved = Core::Circuit::CircuitManager::getInstance().removeConnection(firstPortParent->getId(), startPort->getIndex(), secondPortParent->getId(), endPort->getIndex());
        if (isConnectionRemoved)
        {
            m_scene->removeItem(connection);
            m_connectionsList.removeOne(connection);
            delete connection;
        }
    }
    void SceneEditor::removeElement(UI::CircuitElements::ElementView *element)
    {
        bool isElementRemoved = Core::Circuit::CircuitManager::getInstance().removeComponent(element->getId());
        if (isElementRemoved)
        {
            m_scene->removeItem(element);
            std::remove(m_circuitElements.begin(), m_circuitElements.end(), element);
            delete element;
        }
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
        int type;
        dataStream >> offset >> type;
        QPointF dragPos = dragDropevent->scenePos() - offset;
        event->accept();
        addElement(type, dragPos);
        return true;
    }

    void SceneEditor::addElement(int type, QPointF dragPos)
    {
        const auto elementType = static_cast<Core::Circuit::ElementType>(type);
        auto elementId = Core::Circuit::CircuitManager::getInstance().addComponent(elementType);
        if (!elementId)
        {
            return;
        }
        auto *elementView = UI::ElementFactory::getInstance().createElement(elementType, elementId);
        elementView->setPos(dragPos);
        m_scene->clearSelection();
        elementView->setSelected(true);
        m_currentEventState = EventState::ELEMENT_SELECTED;
        m_scene->addItem(elementView);
        m_circuitElements.push_back(elementView);
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
        return item->type() == UI::CircuitElements::ElementPort::GraphicalType;
    }
}
