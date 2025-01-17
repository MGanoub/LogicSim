#ifndef ANDGATE_H
#define ANDGATE_H

#include "Core/Circuit/Components/component.h"

namespace Core::Circuit
{
    class ANDGate : public Component
    {
    public:
        ANDGate();
        void computeOutputState() override;
    };
}
#endif // ANDGATE_H
