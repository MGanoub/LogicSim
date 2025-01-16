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
    Component *ComponentsFactory::createComponent(ElementType type)
    {
        switch (type)
        {
        case ElementType::VCC:
        {
            return new VCCInput();
        }
        case ElementType::LED:
        {
            return new LED();
        }
        case ElementType::AND_GATE:
        {
            return new ANDGate();
        }
        case ElementType::OR_GATE:
        {
            return new ORGate();
        }
        case ElementType::GND:
        {
            return new GNDInput();
        }
        case ElementType::UNKNOWN:
        default:
            break;
        }
        return new Component();
    }
}