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
            setPixmap(":/outputs/WhiteLedOn.png");
            break;
        }
        case Core::Circuit::State::OFF:
        {
            setPixmap(":/outputs/WhiteLedOff.png");
            break;
        }
        default:
            break;
        }
        update();
    }
}
