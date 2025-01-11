#include "elementView.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace UI::CustomWidgets
{
    ElementView::ElementView(Core::Circuit::ElementType type, QGraphicsItem *parent)
        : QGraphicsObject(parent), m_type(type)
    {
    }

    QRectF ElementView::boundingRect() const
    {
        if (m_pixmap == nullptr)
        {
            return QRectF();
        }
        return m_pixmap->rect();
    }

    void ElementView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        Q_UNUSED(widget)
        painter->setClipRect(option->exposedRect);
        /*
        if (isSelected())
        {
            painter->setBrush(m_selectionBrush);
            painter->setPen(QPen(m_selectionPen, 0.5, Qt::SolidLine));
            painter->drawRoundedRect(boundingRect(), 5, 5);
        }
        */
        painter->drawPixmap(QPoint(0, 0), *m_pixmap);
    }

    void ElementView::setPixmap(const QString &pixmapPath)
    {
        m_pixmap = new QPixmap(pixmapPath);
    }
}
