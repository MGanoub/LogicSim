#ifndef ORGATE_H
#define ORGATE_H

#include "Core/Circuit/Components/component.h"

namespace Core::Circuit
{
    class ORGate : public Component
    {
    public:
        ORGate();
        void computeOutputState() override;
    };
}

#endif // ORGATE_H
