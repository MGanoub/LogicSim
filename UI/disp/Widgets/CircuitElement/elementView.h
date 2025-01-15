#ifndef ELEMENTVIEW_H
#define ELEMENTVIEW_H

#include "Core/Circuit/elementTypeEnum.h"
#include <QGraphicsObject>

namespace UI::CustomWidgets
{
    class ElementView : public QGraphicsObject
    {
        Q_OBJECT

        enum
        {
            Type = QGraphicsItem::UserType + 2
        };

    public:
        explicit ElementView(Core::Circuit::ElementType type, int inputPortCount, int outPutPortCount, int identifier, QGraphicsItem *parent = nullptr);

        QRectF boundingRect() const override;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
        void setPixmap(const QString &pixmapPath);
        int getId();

        virtual void setOutputState(Core::Circuit::State state);

        int type() const override
        {
            return Type;
        }

    private:
        Core::Circuit::ElementType m_type;
        QPixmap *m_pixmap;
        int m_pixmapWidth;
        int m_pixmapHeight;
        int m_maxPortsToDisplayOnOneSide;
        int m_inputPortsCount;
        int m_outPutPortCount;
        int m_identifier;

        void addPorts();
        void updatePortsPosition();
    };
}
#endif // ELEMENTVIEW_H
