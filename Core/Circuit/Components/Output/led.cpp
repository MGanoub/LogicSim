#include "led.h"

namespace Core::Circuit
{
    LED::LED()
        : OutputComponent(1)
    {
    }

    void LED::computeOutputState()
    {
        auto firstPort = m_ports.front();
        firstPort.updateState();
        m_outState = firstPort.getState();
    }
}
