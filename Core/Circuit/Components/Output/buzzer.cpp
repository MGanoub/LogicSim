#include "buzzer.h"

namespace Core::Circuit
{
    Buzzer::Buzzer()
        : Component(1, 0)
    {
    }

    void Buzzer::computeOutputState()
    {
        for (auto &port : m_portsList)
        {
            port.updateState();
            m_state = port.getState();
        }
    }
}
