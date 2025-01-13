#ifndef LED_H
#define LED_H

#include "Core/Circuit/Components/Output/outputComponent.h"

namespace Core::Circuit
{
    class LED : public OutputComponent
    {
    public:
        LED();
        void computeOutputState() override;
    };
}
#endif // LED_H
