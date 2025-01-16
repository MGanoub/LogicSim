#include "gndInput.h"

namespace Core::Circuit
{
    GNDInput::GNDInput()
        : InputComponent(Port(this, Port::Type::OUTPUT, 0, State::OFF))
    {
    }
}