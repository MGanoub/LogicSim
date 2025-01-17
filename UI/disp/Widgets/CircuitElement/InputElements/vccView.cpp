#include "vccView.h"

namespace UI::CircuitElements
{
    VCCView::VCCView(int elementId, QGraphicsItem *parent)
        : ElementView(Core::Circuit::ElementType::VCC, 0, 1, elementId, parent)
    {
        setVisualState(Core::Circuit::State::ON);
    }

    void VCCView::setVisualState(Core::Circuit::State state)
    {
        setPixmap(m_resourceInfo.OnStatePixmapPath);
    }
}
