#include "VCCInput.h"

namespace Core::Circuit
{
    VCCInput::VCCInput()
        : Component(0, 1)
    {
        setState(State::ON);
    }
}
