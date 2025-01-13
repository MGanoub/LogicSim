#ifndef PORT_H
#define PORT_H
#include "../elementTypeEnum.h"

namespace Core::Circuit
{
    class IComponent;
    class Port
    {
    public:
        enum class Type
        {
            INPUT,
            OUTPUT
        };

        enum Number
        {
            PORT_0,
            PORT_1,
            PORT_2,
        };

        Port(IComponent *parentComp, Type portType, int portNumber, State state = State::OFF);

        void setState(State state);
        State getState();

        int getPortNumber();
        void setPortNumber(int num);
        void setParentComp(IComponent *component);
        void connectTo(Port *otherPort);
        void updateState();
        bool isConnected();
        IComponent *getParentComp();

    private:
        State m_state;
        Type m_portType;
        int m_portNumber;
        IComponent *m_parentComp;
        Port *m_otherConnectedPort;
        bool m_isConnected;
    };

}

#endif // PORT_H
