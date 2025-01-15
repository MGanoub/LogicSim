#include "gate.h"

namespace Core::Circuit
{
    LogicGate::LogicGate(int inputPortsCount)
        : Component(Component::Type::LOGIC_GATE),
          m_inputPortsCount(inputPortsCount),
          m_outputPort(Port(this, Port::Type::OUTPUT, 0))
    {
        createInputPorts();
    }

    State LogicGate::getOutputState()
    {
        return m_outState;
    }
    void LogicGate::setOutputState(State state)
    {
        m_outState = state;
    }
    Port *LogicGate::getOutputPort()
    {
        return &m_outputPort;
    }

    std::vector<Port> LogicGate::getInputPorts()
    {
        return m_inputPorts;
    }
    Port *LogicGate::getInputPortAtIndex(int portNumber)
    {
        if (portNumber > m_inputPortsCount)
        {
            return nullptr;
        }
        return &m_inputPorts.at(portNumber);
    }
    void LogicGate::setInputOnPortIndex(int portNumber, State state)
    {
        if (portNumber > m_inputPortsCount)
        {
            return;
        }
        auto *port = &m_inputPorts.at(portNumber);
        port->setState(state);
    }
    int LogicGate::getInputPortsCount()
    {
        return m_inputPortsCount;
    }
    State LogicGate::getOutState()
    {
        return m_outputPort.getState();
    }
    void LogicGate::computeOutputState()
    {
    }

    void LogicGate::createInputPorts()
    {
        for (int i = 0; i < m_inputPortsCount; i++)
        {
            m_inputPorts.emplace_back(Port(this, Port::Type::INPUT, i));
        }
    }

}
