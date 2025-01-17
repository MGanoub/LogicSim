#include "gndView.h"

namespace UI::CircuitElements
{
    GNDView::GNDView(int elementId, QGraphicsItem *parent)
        : ElementView(Core::Circuit::ElementType::GND, 0, 1, elementId, parent)
    {
        setVisualState(Core::Circuit::State::OFF);
    }

    void GNDView::setVisualState(Core::Circuit::State state)
    {
        setPixmap(m_resourceInfo.offStatePixmapPath);
    }
}
