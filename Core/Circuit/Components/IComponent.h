#ifndef ICOMPONENT_H
#define ICOMPONENT_H

namespace Core::Circuit
{
    class Port;
    enum class State;
    class IComponent
    {
    public:
        virtual int getIndentifier() = 0;
        virtual Port *getPortAtIndex(int index) = 0;

        virtual State getState() = 0;
        virtual void setState(State state) = 0;
    };
}

#endif // ICOMPONENT_H
