#include "vccView.h"

namespace UI::CircuitElements
{
    VCCView::VCCView(int elementId, QGraphicsItem *parent)
        : ElementView(Core::Circuit::ElementType::LED, 0, 1, elementId, parent)
    {
        setVisualState(Core::Circuit::State::ON);
    }

    void VCCView::setVisualState(Core::Circuit::State state)
    {
        setPixmap(":/inputs/VCC.png");
    }
}
