#include "port.h"

namespace Core::Circuit
{

Port::Port(IComponent* parentComp, Type portType, int portNumber, State state)
    : m_parentComp(parentComp)
    , m_portType(portType)
    , m_portNumber(portNumber)
    , m_state(state)
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

void Port::setParentComp(IComponent* component)
{
    m_parentComp = component;
}

IComponent *Port::getParentComp()
{
    return m_parentComp;
}
}
