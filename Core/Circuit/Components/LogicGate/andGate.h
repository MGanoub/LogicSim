#ifndef ANDGATE_H
#define ANDGATE_H

#include "gate.h"

namespace Core::Circuit
{
    class ANDGate : public LogicGate
    {
    public:
        ANDGate();
        void computeOutputState() override;
    };
}
#endif // ANDGATE_H
