#include "elementPort.h"
#include <QGraphicsItem>
#include <QPen>

namespace UI::CustomWidgets
{
    ElementPort::ElementPort(QGraphicsItem *parent)
        : QGraphicsPathItem(parent), m_radius(5), m_margin(2)
    {

        QPainterPath p;
        p.addPolygon(QRectF(QPointF(-m_radius, -m_radius), QPointF(m_radius, m_radius)));
        setPath(p);

        setPen(QPen(Qt::darkRed));
        setBrush(Qt::red);
    }

    void ElementPort::UpdateBrush()
    {
        setBrush(Qt::yellow);
        update();
    }

}