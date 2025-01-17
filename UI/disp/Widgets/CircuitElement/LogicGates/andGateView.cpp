#include "ANDGateView.h"

namespace UI::CircuitElements
{
    ANDGateView::ANDGateView(int elementId, QGraphicsItem *parent)
        : ElementView(Core::Circuit::ElementType::AND_GATE, 2, 1, elementId, parent)
    {
        setVisualState(Core::Circuit::State::ON);
    }

    void ANDGateView::setVisualState(Core::Circuit::State state)
    {
        setPixmap(":/LogicGates/ANDGate.png");
    }
}
