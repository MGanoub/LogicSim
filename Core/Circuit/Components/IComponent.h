#ifndef ICOMPONENT_H
#define ICOMPONENT_H

namespace Core::Circuit
{
    class IComponent
    {
    public:
        virtual int getIndentifier() = 0;
    };

    class OutputComponent : public IComponent
    {
    public:
        // virtual QList<Port> getInputPorts() = 0;
        //virtual Port *getInputPortAtIndex(int portNumber) = 0;
        //virtual void setInputOnPortIndex(int portNumber) = 0;
    };
}

#endif // ICOMPONENT_H
