#include "componentsFactory.h"
#include "Core/Circuit/Components/Input/GNDInput.h"
#include "Core/Circuit/Components/Input/VCCInput.h"
#include "Core/Circuit/Components/LogicGate/andGate.h"
#include "Core/Circuit/Components/LogicGate/orGate.h"
#include "Core/Circuit/Components/Output/led.h"

namespace Core::Circuit
{
    ComponentsFactory &ComponentsFactory::getInstance()
    {
        static ComponentsFactory s_instance;
        return s_instance;
    }
    std::unique_ptr<Component> ComponentsFactory::createComponent(ElementType type)
    {
        switch (type)
        {
        case ElementType::VCC:
        {
            return std::make_unique<VCCInput>();
        }
        case ElementType::LED:
        {
            return std::make_unique<LED>();
        }
        case ElementType::AND_GATE:
        {
            return std::make_unique<ANDGate>();
        }
        case ElementType::OR_GATE:
        {
            return std::make_unique<ORGate>();
        }
        case ElementType::GND:
        {
            return std::make_unique<GNDInput>();
        }
        case ElementType::UNKNOWN:
        default:
            break;
        }
        return std::make_unique<Component>(0, 0);
    }
}