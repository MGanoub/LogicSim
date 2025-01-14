#include "componentsFactory.h"
#include "Core/Circuit/Components/Input/VCCInput.h"
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
        case ElementType::UNKNOWN:
        default:
            break;
        }
        return new Component();
    }
}