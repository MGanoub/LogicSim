#ifndef ICOMPONENT_H
#define ICOMPONENT_H

namespace Core::Circuit
{
    class IComponent
    {
    public:
        virtual int getIndentifier() = 0;
    };
}

#endif // ICOMPONENT_H
