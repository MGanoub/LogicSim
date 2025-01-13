#include "inputComponent.h"

namespace Core::Circuit
{
    InputComponent::InputComponent(Port outputPort)
        : m_outputPort(outputPort), m_type(Component::Type::INPUT)
    {
    }

    void InputComponent::setType(Component::Type type)
    {
        m_type = type;
    }
    Component::Type InputComponent::getType()
    {
        return m_type;
    }

    State InputComponent::getOutputState()
    {
        return m_outputPort.getState();
    }

    void InputComponent::setOutputState(State state)
    {
        m_outputPort.setState(state);
    }
}
