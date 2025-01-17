#include "andGate.h"

namespace Core::Circuit
{
    ANDGate::ANDGate()
        : Component(2, 1)
    {
    }
    void ANDGate::computeOutputState()
    {
        if (!areAllInputPortsConnected())
        {
            setState(State::OFF);
            return;
        }
        updateInputPortsState();
        bool outputState = true;
        for (auto port : m_portsList)
        {
            if (port.isInputType())
            {
                outputState &= static_cast<bool>(port.getState());
            }
        }
        setState(static_cast<State>(outputState));
    }
}
