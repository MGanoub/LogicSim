#ifndef NOTGATE_H
#define NOTGATE_H

#include "Core/Circuit/Components/component.h"

namespace Core::Circuit
{
    class NOTGate : public Component
    {
    public:
        NOTGate();
        void computeOutputState() override;
    };
}
#endif // NOTGATE_H
