#ifndef ELEMENTVIEW_H
#define ELEMENTVIEW_H

#include "Core/Circuit/CircuitEnums.h"
#include "UI/Managers/resourceManager.h"
#include <QGraphicsObject>

namespace UI::CircuitElements
{
    class ElementView : public QGraphicsObject
    {
        Q_OBJECT
    public:
        enum
        {
            GraphicalType = QGraphicsItem::UserType + 2
        };

        explicit ElementView(Core::Circuit::ElementType type, int inputPortCount, int outPutPortCount, int identifier, QGraphicsItem *parent = nullptr);

        QRectF boundingRect() const override;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
        void setPixmap(const QString &pixmapPath);
        int getId();

        virtual void setVisualState(Core::Circuit::State state);
        virtual void setAudioState(Core::Circuit::State state);
        void setState(Core::Circuit::State state);

        int type() const override
        {
            return GraphicalType;
        }

    protected:
        ResourceManager::ResourceInfo m_resourceInfo;

    private:
        Core::Circuit::ElementType m_type;
        QPixmap *m_pixmap;
        int m_pixmapWidth;
        int m_pixmapHeight;
        int m_maxPortsToDisplayOnOneSide;
        int m_inputPortsCount;
        int m_outPutPortCount;
        int m_identifier;
        bool m_isConnected;

        void addPorts();
    };
}
#endif // ELEMENTVIEW_H
