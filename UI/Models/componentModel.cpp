#include "componentModel.h"

namespace UI
{
    std::vector<Core::Circuit::ElementType> ComponentModel::getAvailableSourceComponents()
    {
        return {
            Core::Circuit::ElementType::VCC,
            Core::Circuit::ElementType::GND,
            Core::Circuit::ElementType::LED,
            Core::Circuit::ElementType::BUZZER,
        };
    }
    std::vector<Core::Circuit::ElementType> ComponentModel::getAvailableLogicGateComponents()
    {
        return {
            Core::Circuit::ElementType::AND_GATE,
            Core::Circuit::ElementType::OR_GATE,
            Core::Circuit::ElementType::NOT_GATE,
        };
    }
}
