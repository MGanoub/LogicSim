#include "elementConnection.h"

#include "elementPort.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace UI::CustomWidgets
{
    ElementConnection::ElementConnection(QGraphicsItem *parent)
        : QGraphicsPathItem(parent)
    {
        setPen(QPen(Qt::green, 4, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        setZValue(-1);
    }

    void ElementConnection::setStartPos(const QPointF &pos)
    {
        m_startPos = pos;
    }
    void ElementConnection::setEndPos(const QPointF &pos)
    {
        m_endPos = pos;
    }

    void ElementConnection::updatePath()
    {
        QPainterPath p;

        p.moveTo(m_startPos);

        qreal dx = m_endPos.x() - m_startPos.x();
        qreal dy = m_endPos.y() - m_startPos.y();
        QPointF point1(m_startPos.x() + dx * 0.25, m_startPos.y() + dy * 0.1);
        QPointF point2(m_startPos.x() + dx * 0.75, m_startPos.y() + dy * 0.9);

        p.cubicTo(point1, point2, m_endPos);

        setPath(p);
    }

    void ElementConnection::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        Q_UNUSED(widget)
        painter->setClipRect(option->exposedRect);

        if (isSelected())
        {
            painter->setPen(QPen(Qt::green, 5));
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
        connectionItem->setBrush(Qt::green);
        connectionItem->update();
        auto *elementView = static_cast<UI::CustomWidgets::ElementView *>(connectionItem->parentObject());
        elementView->setPixmap(":/outputs/WhiteLedOn.png");
    }

}
