#include "pressButton.h"

namespace Core::Circuit
{
    PressButton::PressButton()
        : Component(0, 1)
    {
        setState(State::OFF);
    }
}