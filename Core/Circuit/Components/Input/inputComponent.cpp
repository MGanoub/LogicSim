#include "inputComponent.h"

namespace Core::Circuit
{
    InputComponent::InputComponent(Port outputPort)
        : Component(Component::Type::INPUT), m_outputPort(outputPort)
    {
    }

    State InputComponent::getOutputState()
    {
        return m_outputPort.getState();
    }

    void InputComponent::setOutputState(State state)
    {
        m_outputPort.setState(state);
    }

    Port *InputComponent::getOutputPort()
    {
        return &m_outputPort;
    }
}
