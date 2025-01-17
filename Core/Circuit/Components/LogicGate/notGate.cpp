#include "notGate.h"

namespace Core::Circuit
{
    NOTGate::NOTGate()
        : Component(1, 1)
    {
    }
    void NOTGate::computeOutputState()
    {
        if (!areAllInputPortsConnected())
        {
            setState(State::OFF);
            return;
        }
        updateInputPortsState();
        bool outputState = false;
        for (auto port : m_portsList)
        {
            if (port.isInputType())
            {
                outputState = !static_cast<bool>(port.getState());
            }
        }
        setState(static_cast<State>(outputState));
    }
}
