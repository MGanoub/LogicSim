#include "notGateView.h"

namespace UI::CircuitElements
{
    NOTGateView::NOTGateView(int elementId, QGraphicsItem *parent)
        : ElementView(Core::Circuit::ElementType::NOT_GATE, 1, 1, elementId, parent)
    {
        setVisualState(Core::Circuit::State::ON);
    }

    void NOTGateView::setVisualState(Core::Circuit::State state)
    {
        setPixmap(m_resourceInfo.OnStatePixmapPath);
    }
}
