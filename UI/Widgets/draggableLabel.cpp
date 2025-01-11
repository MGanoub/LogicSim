#include "draggableLabel.h"
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>

namespace UI::CustomWidgets
{
    DraggableLabel::DraggableLabel(QWidget *parent) : QLabel(parent) {}

    DraggableLabel::DraggableLabel(const QPixmap &pixmap, int type, const QString &name, QWidget *parent)
        : QLabel(parent), m_type(type), m_name(name)
    {
        setPixmapData(pixmap);
    }

    void DraggableLabel::mousePressEvent(QMouseEvent *event)
    {
        startDrag(event->pos());
    }

    void DraggableLabel::setPixmapData(const QPixmap &pixmapData)
    {
        m_pixmapData = pixmapData;
        setPixmap(pixmapData.scaled(64, 64));
    }

    const QPixmap &DraggableLabel::pixmapData() const
    {
        return m_pixmapData;
    }

    QString DraggableLabel::name() const
    {
        return m_name;
    }

    void DraggableLabel::setName(const QString &name)
    {
        m_name = name;
    }

    void DraggableLabel::startDrag(QPoint pos)
    {
        QPixmap pixMap = pixmapData();
        if (pos.isNull())
        {
            pos = pixmap(Qt::ReturnByValue).rect().center();
        }
        QByteArray itemData;
        QDataStream dataStream(&itemData, QIODevice::WriteOnly);
        /*
        QString text = ElementFactory::typeToText(m_elementType);
        if (text.contains("_")) {
            text = text.split("_").last();
        }
        ElementType type = ElementFactory::textToType(text);
        /*  qDebug() << objectName(); */

        dataStream << QPointF(pos) << static_cast<qint32>(10);

        auto *mimeData = new QMimeData;
        mimeData->setData("application/x-dnditemdata", itemData);
        auto *drag = new QDrag(parent());
        drag->setMimeData(mimeData);
        drag->setPixmap(pixMap);
        drag->setHotSpot(pos);
        drag->exec(Qt::CopyAction, Qt::CopyAction);
    }

}
