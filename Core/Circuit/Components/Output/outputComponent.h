#ifndef OUTPUTCOMPONENT_H
#define OUTPUTCOMPONENT_H

#include "Core/Circuit/Components/component.h"
#include "Core/Circuit/Components/port.h"
#include <vector>

namespace Core::Circuit
{
    class OutputComponent : public Component
    {
    public:
        explicit OutputComponent(int inputPortsCount);

        std::vector<Port> getInputPorts();
        Port *getInputPortAtIndex(int portNumber);
        void setInputOnPortIndex(int portNumber, State state);
        int getPortsCount();

    protected:
        int m_inputPortsCount;
        std::vector<Port> m_ports;

        void createInputPorts();
    };
}

#endif // OUTPUTCOMPONENT_H
