#ifndef LED_H
#define LED_H

#include "Core/Circuit/Components/component.h"

namespace Core::Circuit
{
    class LED : public Component
    {
    public:
        LED();
        void computeOutputState() override;
    };
}
#endif // LED_H
