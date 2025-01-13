#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include "Core/Circuit/Components/component.h"
#include "Core/Circuit/Components/port.h"

namespace Core::Circuit
{
    class InputComponent : public Component
    {
    public:
        explicit InputComponent(Port outputPort);

        State getOutputState();
        void setOutputState(State state);

    protected:
        Port m_outputPort;
    };
}
#endif // INPUTCOMPONENT_H
