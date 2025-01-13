#include "outputComponent.h"

namespace Core::Circuit
{
    OutputComponent::OutputComponent(int inputPortsCount)
        : Component(Type::OUTPUT),
          m_inputPortsCount(inputPortsCount)
    {
        createInputPorts();
    }

    void OutputComponent::createInputPorts()
    {
        for (int i = 0; i < m_inputPortsCount; i++)
        {
            m_ports.emplace_back(Port(this, Port::Type::INPUT, Port::Number::PORT_0, State::OFF));
        }
    }

    std::vector<Port> OutputComponent::getInputPorts()
    {
        return m_ports;
    }
    Port *OutputComponent::getInputPortAtIndex(int portNumber)
    {
        if (portNumber > m_inputPortsCount)
        {
            return nullptr;
        }
        return &m_ports.at(portNumber);
    }
    void OutputComponent::setInputOnPortIndex(int portNumber, State state)
    {
        if (portNumber > m_inputPortsCount)
        {
            return;
        }
        auto port = m_ports.at(portNumber);
        port.setState(state);
    }

    int OutputComponent::getPortsCount()
    {
        return m_inputPortsCount;
    }
}
