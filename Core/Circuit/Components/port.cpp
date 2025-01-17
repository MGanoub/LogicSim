#include "port.h"

namespace Core::Circuit
{

    Port::Port(IComponent *parentComp, Type portType, int portNumber, State state)
        : m_parentComp(parentComp), m_portType(portType), m_portNumber(portNumber), m_state(state), m_otherConnectedPort(nullptr), m_isConnected(false)
    {
    }

    void Port::setState(State state)
    {
        m_state = state;
    }

    State Port::getState()
    {
        return m_state;
    }

    int Port::getPortNumber()
    {
        return m_portNumber;
    }

    void Port::setParentComp(IComponent *component)
    {
        m_parentComp = component;
    }

    IComponent *Port::getParentComp()
    {
        return m_parentComp;
    }

    void Port::connectTo(Port *otherPort)
    {
        if (otherPort == nullptr)
        {
            return;
        }
        m_otherConnectedPort = otherPort;
        m_isConnected = true;
    }
    void Port::disconnect()
    {
        if (!m_isConnected)
        {
            return;
        }
        m_otherConnectedPort = nullptr;
        m_isConnected = false;
        m_state= State::OFF;
    }

    bool Port::isConnected()
    {
        return m_isConnected;
    }

    void Port::updateState()
    {
        if (!isConnected() || (m_otherConnectedPort == nullptr))
        {
            return;
        }
        m_state = m_otherConnectedPort->getState();
    }

    bool Port::isOutputType()
    {
        return m_portType == Port::Type::OUTPUT;
    }
    bool Port::isInputType()
    {
        return m_portType == Port::Type::INPUT;
    }
}
