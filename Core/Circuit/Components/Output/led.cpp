#include "led.h"

namespace Core::Circuit
{
    LED::LED()
        : Component(1, 0)
    {
    }

    void LED::computeOutputState()
    {
        for (auto &port : m_portsList)
        {
            port.updateState();
            m_state = port.getState();
        }
    }
}
