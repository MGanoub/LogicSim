#include "sceneEditor.h"
#include <QEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsSceneMouseEvent>
#include <QIODevice>
#include <QMimeData>

namespace UI
{

    SceneEditor::SceneEditor(QObject *parent, QGraphicsScene *scene)
        : QObject(parent), m_scene(scene)
    {
        m_scene->installEventFilter(this);
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
        auto *graphicPixmap = new QGraphicsPixmapItem(pixmap);
        graphicPixmap->setOffset(pos);
        graphicPixmap->setFlag(QGraphicsItem::ItemIsMovable);
        graphicPixmap->setVisible(true);
        m_scene->addItem(graphicPixmap);
        m_scene->update();
        return true;
    }
}
