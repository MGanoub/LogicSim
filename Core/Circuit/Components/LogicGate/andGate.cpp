#include "andGate.h"

namespace Core::Circuit
{
    ANDGate::ANDGate()
        : LogicGate(2)
    {
    }
    void ANDGate::computeOutputState()
    {
        bool outputState = false;
        for (auto input : m_inputPorts)
        {
            outputState &= static_cast<bool>(input.getState());
        }
        m_outState = (outputState) ? State::ON : State::OFF;
    }
}