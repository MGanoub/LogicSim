#ifndef ELEMENTVIEW_H
#define ELEMENTVIEW_H

#include "../../Core/Circuit/elementTypeEnum.h"
#include <QGraphicsObject>

namespace UI::CustomWidgets
{
    class ElementView : public QGraphicsObject
    {
        Q_OBJECT

    public:
        explicit ElementView(Core::Circuit::ElementType type, int inputPortCount, QGraphicsItem *parent = nullptr);

        QRectF boundingRect() const override;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
        void setPixmap(const QString &pixmapPath);

    private:
        Core::Circuit::ElementType m_type;
        QPixmap *m_pixmap;
        int m_inputPortsCount;

        void addPorts();
        void updatePortsPosition();
    };
}
#endif // ELEMENTVIEW_H
