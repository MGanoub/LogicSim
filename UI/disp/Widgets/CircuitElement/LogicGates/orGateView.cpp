#include "orGateView.h"

namespace UI::CircuitElements
{
    ORGateView::ORGateView(int elementId, QGraphicsItem *parent)
        : ElementView(Core::Circuit::ElementType::OR_GATE, 2, 1, elementId, parent)
    {
        setVisualState(Core::Circuit::State::ON);
    }

    void ORGateView::setVisualState(Core::Circuit::State state)
    {
        setPixmap(m_resourceInfo.OnStatePixmapPath);
    }
}
