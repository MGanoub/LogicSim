#include "orGate.h"

namespace Core::Circuit
{
    ORGate::ORGate()
        : LogicGate(2)
    {
    }
    void ORGate::computeOutputState()
    {
        if (!areAllInputPortsConnected())
        {
            setOutputState(State::OFF);
            return;
        }
        updateInputPortsState();
        bool outputState = false;
        for (auto input : m_inputPorts)
        {
            outputState |= static_cast<bool>(input.getState());
        }
        m_outState = (outputState) ? State::ON : State::OFF;
        m_outputPort.setState(m_outState);
    }
}
