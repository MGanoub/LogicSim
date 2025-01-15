#include "ANDGate.h"

namespace UI::CircuitElements
{
    ANDGate::ANDGate(int elementId, QGraphicsItem *parent)
        : ElementView(Core::Circuit::ElementType::LED, 2, 1, elementId, parent)
    {
        setVisualState(Core::Circuit::State::ON);
    }

    void ANDGate::setVisualState(Core::Circuit::State state)
    {
        setPixmap(":/LogicGates/ANDGate.png");
    }
}
