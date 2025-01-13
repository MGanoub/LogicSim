#include "VCCInput.h"

namespace Core::Circuit
{
    VCCInput::VCCInput()
        : InputComponent(Port(this, Port::Type::OUTPUT, 0, State::ON))
    {
    }
}
