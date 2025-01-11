#include "sceneEditor.h"
#include "../UI/Widgets/elementView.h"
#include "../UI/mainwindow.h"
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
    }

    bool SceneEditor::eventFilter(QObject *obj, QEvent *evt)
    {
        /*
        if (evt->type() == QEvent::GraphicsSceneMousePress)
        {
            const auto *mouseEvt = dynamic_cast<QGraphicsSceneMouseEvent *>(evt);
            const auto mousePos = mouseEvt->scenePos();

            QPixmap pixmap(":/inputs/buttonOn.png");
            auto *graphicPixmap = new QGraphicsPixmapItem(pixmap);
            graphicPixmap->setOffset(mousePos);
            graphicPixmap->setFlag(QGraphicsItem::ItemIsMovable);
            graphicPixmap->setVisible(true);
            m_scene->addItem(graphicPixmap);
            m_scene->update();
        }
        */
        if (evt->type() == QEvent::GraphicsSceneDrop)
        {
            auto *dragDropevent = dynamic_cast<QGraphicsSceneDragDropEvent *>(evt);
            return handleDropEvent(dragDropevent);
        }
        return true;
    }
    bool SceneEditor::handleDropEvent(QGraphicsSceneDragDropEvent *event)
    {
        /* Verify if mimetype is compatible. */
        if (!event->mimeData()->hasFormat("application/x-dnditemdata"))
        {
            return false;
        }
        /* Extracting mimedata from drop event. */
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        QPointF offset;
        qint32 type;
        dataStream >> offset >> type;
        QPointF pos = event->scenePos() - offset;
        event->accept();

        QPixmap pixmap(":/inputs/VCC.png");
        auto *elementView = new UI::CustomWidgets::ElementView(Core::Circuit::ElementType::VCC);
        elementView->setPixmap(":/inputs/VCC.png");
        elementView->setPos(pos);
        m_scene->addItem(elementView);
        auto *window = qobject_cast<MainWindow *>(this->parent());
        window->refresh();
        return true;
    }
}
