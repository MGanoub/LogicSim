#ifndef LogicGate_H
#define LogicGate_H

#include "Core/Circuit/Components/component.h"
#include "Core/Circuit/Components/port.h"
#include <vector>

namespace Core::Circuit
{
    class LogicGate : public Component
    {
    public:
        explicit LogicGate(int inputPortsCount);

        State getOutputState();
        void setOutputState(State state);
        Port *getOutputPort();

        std::vector<Port> getInputPorts();
        Port *getInputPortAtIndex(int portNumber);
        void setInputOnPortIndex(int portNumber, State state);
        int getInputPortsCount();
        State getOutState();
        virtual void computeOutputState();

    protected:
        int m_inputPortsCount;
        std::vector<Port> m_inputPorts;
        State m_outState;
        Port m_outputPort;

        void createInputPorts();
        void updateInputPortsState();
        bool areAllInputPortsConnected();
    };
}
#endif // LogicGate_H
