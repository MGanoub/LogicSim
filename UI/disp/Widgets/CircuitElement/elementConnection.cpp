#include "elementConnection.h"

#include "elementPort.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace UI::CircuitElements
{
    ElementConnection::ElementConnection(QGraphicsItem *parent)
        : QGraphicsPathItem(parent), m_startPort(nullptr), m_endPort(nullptr)
    {
        setFlags(QGraphicsItem::ItemIsSelectable);
        setPen(QPen(Qt::green, 4, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        setZValue(-1);
    }
    ElementConnection::~ElementConnection()
    {
        if (m_endPort != nullptr)
        {
            m_endPort->disconnected();
            m_startPort->disconnected();
        }
    }

    void ElementConnection::setStartPort(ElementPort *port)
    {
        m_startPort = port;
        m_startPos = port->scenePos();
    }
    void ElementConnection::setEndPort(ElementPort *port)
    {
        m_endPort = port;
        m_endPos = port->scenePos();
    }

    void ElementConnection::setEndPos(const QPointF &pos)
    {
        m_endPos = pos;
    }

    ElementPort *ElementConnection::getStartPort()
    {
        return m_startPort;
    }
    ElementPort *ElementConnection::getEndPort()
    {
        return m_endPort;
    }

    void ElementConnection::updatePath()
    {
        QPainterPath p;
        m_startPos = m_startPort->scenePos();
        if (m_endPort)
        {
            m_endPos = m_endPort->scenePos();
        }
        p.moveTo(m_startPos);

        qreal dx = m_endPos.x() - m_startPos.x();
        qreal dy = m_endPos.y() - m_startPos.y();
        QPointF point1(m_startPos.x() + dx * 0.25, m_startPos.y() + dy * 0.1);
        QPointF point2(m_startPos.x() + dx * 0.75, m_startPos.y() + dy * 0.9);

        p.cubicTo(point1, point2, m_endPos);

        setPath(p);
        update();
    }

    void ElementConnection::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        Q_UNUSED(widget)
        painter->setClipRect(option->exposedRect);

        if (isSelected())
        {
            const auto selectionColor = QColor(175, 0, 0, 255);
            painter->setPen(QPen(selectionColor, 5));
        }
        else
        {
            painter->setPen(QPen(Qt::green, 4, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        }

        painter->drawPath(path());
    }

    void ElementConnection::makeConnection(ElementPort *connectionItem)
    {
        if (connectionItem == nullptr)
        {
            return;
        }
        setEndPort(connectionItem);
        m_startPort->connected();
        m_endPort->connected();
    }

    bool ElementConnection::isConnectedWith(int identifier)
    {
        if (m_startPort == nullptr || m_endPort == nullptr)
        {
            return false;
        }
        return (m_startPort->getParent()->getId() == identifier) || (m_endPort->getParent()->getId() == identifier);
    }
}
