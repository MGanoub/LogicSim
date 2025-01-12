#ifndef ELEMENTCONNECTION_H
#define ELEMENTCONNECTION_H

#include <QGraphicsPathItem>

namespace UI::CustomWidgets
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

        void setStartPos(const QPointF &pos);
        void setEndPos(const QPointF &pos);
        void updatePath();
        void makeConnection(UI::CustomWidgets::ElementPort *ConnectionItem);

        int type() const override
        {
            return Type;
        }
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    private:
        QPointF m_startPos;
        QPointF m_endPos;
    };
}
#endif // ELEMENTCONNECTION_H
