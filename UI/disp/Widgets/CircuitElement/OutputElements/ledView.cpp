#include "ledView.h"

namespace UI::CircuitElements
{
    LEDView::LEDView(int elementId, QGraphicsItem *parent)
        : ElementView(Core::Circuit::ElementType::LED, 1, 0, elementId, parent)
    {
        setVisualState(Core::Circuit::State::OFF);
    }

    void LEDView::setVisualState(Core::Circuit::State state)
    {
        switch (state)
        {
        case Core::Circuit::State::ON:
        {
            setPixmap(m_resourceInfo.OnStatePixmapPath);
            break;
        }
        case Core::Circuit::State::OFF:
        {
            setPixmap(m_resourceInfo.offStatePixmapPath);
            break;
        }
        default:
            break;
        }
        update();
    }
}
