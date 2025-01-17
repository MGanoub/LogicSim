#ifndef COMPONENT_H
#define COMPONENT_H

#include "Core/Circuit/Components/IComponent.h"
#include "Core/Circuit/Components/port.h"
#include <Core/Circuit/CircuitEnums.h>
#include <vector>

namespace Core::Circuit
{
    class Component : public IComponent
    {
    public:
        Component(int inputPortsCount, int outputPortsCount);

        Port *getPortAtIndex(int index) override;

        int getIndentifier() override;
        State getState() override;
        void setState(State state) override;

        virtual void computeOutputState();
        bool areAllInputPortsConnected();

    protected:
        int m_identifier;
        std::vector<Port> m_portsList;
        int m_inputPortsCount;
        int m_outputPortsCount;
        State m_state;

        void createPorts();
        void updateInputPortsState();
    };
}
#endif // COMPONENT_H
