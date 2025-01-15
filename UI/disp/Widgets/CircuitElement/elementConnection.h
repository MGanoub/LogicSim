#ifndef ELEMENTCONNECTION_H
#define ELEMENTCONNECTION_H

#include <QGraphicsPathItem>

namespace UI::CircuitElements
{
    class ElementPort;
    class ElementConnection : public QGraphicsPathItem
    {
    public:
        enum
        {
            Type = QGraphicsItem::UserType + 3
        };

        explicit ElementConnection(QGraphicsItem *parent = nullptr);

        void setStartPort(ElementPort *port);
        void setEndPort(ElementPort *port);

        void setEndPos(const QPointF &pos);

        ElementPort *getStartPort();
        ElementPort *getEndPort();

        void updatePath();
        void makeConnection(ElementPort *ConnectionItem);

        int type() const override
        {
            return Type;
        }
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    private:
        ElementPort *m_startPort;
        ElementPort *m_endPort;

        QPointF m_startPos;
        QPointF m_endPos;
    };
}
#endif // ELEMENTCONNECTION_H
