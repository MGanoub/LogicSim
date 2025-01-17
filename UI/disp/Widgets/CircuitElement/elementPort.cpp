#include "elementPort.h"
#include <QGraphicsItem>
#include <QPen>

namespace UI::CircuitElements
{
    ElementPort::ElementPort(ElementPort::PortType type, ElementView *parent)
        : QGraphicsPathItem(parent), m_parent(parent), m_radius(5), m_margin(2), m_portType(type),
          m_connected(false)
    {

        QPainterPath p;
        p.addPolygon(QRectF(QPointF(-m_radius, -m_radius), QPointF(m_radius, m_radius)));
        setPath(p);

        setPen(QPen(Qt::darkRed));
        setBrush(Qt::red);
    }

    int ElementPort::type() const
    {
        return GraphicalType;
    }

    ElementPort::PortType ElementPort::getPortType()
    {
        return m_portType;
    }

    ElementView *ElementPort::getParent()
    {
        return m_parent;
    }

    void ElementPort::setIndex(int portNumber)
    {
        m_index = portNumber;
    }
    int ElementPort::getIndex()
    {
        return m_index;
    }
    void ElementPort::connected()
    {
        setBrush(Qt::green);
        update();
        m_connected = true;
    }
    void ElementPort::disconnected()
    {
        if (!m_connected)
        {
            return;
        }
        setBrush(Qt::red);
        update();
        m_connected = false;
    }
}
