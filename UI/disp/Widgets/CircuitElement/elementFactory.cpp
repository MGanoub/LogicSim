#include "elementFactory.h"
#include "UI/disp/Widgets/CircuitElement/OutputElements/ledView.h"

namespace UI
{
    ElementFactory &ElementFactory::getInstance()
    {
        static ElementFactory s_instance;
        return s_instance;
    }

    UI::CustomWidgets::ElementView *ElementFactory::createElement(Core::Circuit::ElementType type, int elementId, QGraphicsItem *parent)
    {
        switch (type)
        {
        case Core::Circuit::ElementType::VCC:
        {
            return new UI::CircuitElements::LEDView(elementId, parent);
        }
        case Core::Circuit::ElementType::LED:
        {
            return new UI::CircuitElements::LEDView(elementId, parent);
        }
        case Core::Circuit::ElementType::UNKNOWN:
        default:
            break;
        }
        int unknownElementTypeIdentifier = -1;
        return new UI::CustomWidgets::ElementView(type, 0, 0, unknownElementTypeIdentifier, parent);
    }
}
