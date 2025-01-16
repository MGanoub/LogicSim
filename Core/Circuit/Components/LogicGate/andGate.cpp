#include "andGate.h"

namespace Core::Circuit
{
    ANDGate::ANDGate()
        : LogicGate(2)
    {
    }
    void ANDGate::computeOutputState()
    {
        if (!areAllInputPortsConnected())
        {
            setOutputState(State::OFF);
            return;
        }
        updateInputPortsState();
        bool outputState = true;
        for (auto input : m_inputPorts)
        {
            outputState &= static_cast<bool>(input.getState());
        }
        m_outState = (outputState) ? State::ON : State::OFF;
        m_outputPort.setState(m_outState);
    }
}
