#ifndef ORGATE_H
#define ORGATE_H

#include "gate.h"

namespace Core::Circuit
{
    class ORGate : public LogicGate
    {
    public:
        ORGate();
        void computeOutputState() override;
    };
}

#endif // ORGATE_H
