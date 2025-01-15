#include "vccView.h"

namespace UI::CircuitElements
{
    VCCView::VCCView(int elementId, QGraphicsItem *parent)
        : ElementView(Core::Circuit::ElementType::LED, 0, 1, elementId, parent)
    {
        setOutputState(Core::Circuit::State::ON);
    }

}
