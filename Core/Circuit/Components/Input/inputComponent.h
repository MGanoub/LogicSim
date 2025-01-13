#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include "Core/Circuit/Components/component.h"
#include "Core/Circuit/Components/port.h"

namespace Core::Circuit
{
    class InputComponent : public Component
    {
    public:
        InputComponent() = default;
        InputComponent(Port outputPort);

        void setType(Component::Type type) override;
        Component::Type getType() override;

        State getOutputState();
        void setOutputState(State state);

    private:
        Port m_outputPort;
        Component::Type m_type;
    };
}
#endif // INPUTCOMPONENT_H
