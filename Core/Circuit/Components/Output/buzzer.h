#ifndef BUZZER_H
#define BUZZER_H

#include "Core/Circuit/Components/component.h"

namespace Core::Circuit
{
    class Buzzer : public Component
    {
    public:
        Buzzer();
        void computeOutputState() override;
    };
}

#endif // BUZZER_H
