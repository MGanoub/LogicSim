#include "component.h"
#include <Core/Circuit/Components/port.h>
namespace Core::Circuit
{
    Component::Component(int inputPortsCount, int outputPortsCount)
        : m_inputPortsCount(inputPortsCount), m_outputPortsCount(outputPortsCount), m_state(State::OFF)
    {
        static int s_uniqueIdentifier = 1;
        m_identifier = s_uniqueIdentifier++;
        createPorts();
    }

    int Component::getIndentifier()
    {
        return m_identifier;
    }

    void Component::setState(State state)
    {
        m_state = state;
        for (auto &port : m_portsList)
        {
            if (port.isOutputType())
            {
                port.setState(m_state);
            }
        }
    }

    State Component::getState()
    {
        return m_state;
    }

    Port *Component::getPortAtIndex(int index)
    {
        return &m_portsList.at(index);
    }

    void Component::createPorts()
    {
        const auto totalPorts = m_inputPortsCount + m_outputPortsCount;
        for (int i = 0; i < totalPorts; i++)
        {
            auto portType = ((i >= m_inputPortsCount) || (m_inputPortsCount == 0)) ? Port::Type::OUTPUT : Port::Type::INPUT;
            m_portsList.emplace_back(Port(this, portType, i));
        }
    }
    void Component::computeOutputState()
    {
    }

    bool Component::areAllInputPortsConnected()
    {
        for (int i = 0; i < m_inputPortsCount; i++)
        {
            auto &port = m_portsList.at(i);
            if (!port.isConnected())
            {
                return false;
            }
        }
        return true;
    }

    void Component::updateInputPortsState()
    {
        for (auto &port : m_portsList)
        {
            if ((port.isInputType()) && port.isConnected())
            {
                port.updateState();
            }
        }
    }
}
