#include "elementFactory.h"
#include "UI/disp/Widgets/CircuitElement/InputElements/gndView.h"
#include "UI/disp/Widgets/CircuitElement/InputElements/pressButtonView.h"
#include "UI/disp/Widgets/CircuitElement/InputElements/vccView.h"
#include "UI/disp/Widgets/CircuitElement/LogicGates/andGateView.h"
#include "UI/disp/Widgets/CircuitElement/LogicGates/notGateView.h"
#include "UI/disp/Widgets/CircuitElement/LogicGates/orGateView.h"
#include "UI/disp/Widgets/CircuitElement/OutputElements/buzzerView.h"
#include "UI/disp/Widgets/CircuitElement/OutputElements/ledView.h"

namespace UI
{
    ElementFactory &ElementFactory::getInstance()
    {
        static ElementFactory s_instance;
        return s_instance;
    }

    UI::CircuitElements::ElementView *ElementFactory::createElement(Core::Circuit::ElementType type, int elementId, QGraphicsItem *parent)
    {
        switch (type)
        {
        case Core::Circuit::ElementType::VCC:
        {
            return new UI::CircuitElements::VCCView(elementId, parent);
        }
        case Core::Circuit::ElementType::GND:
        {
            return new UI::CircuitElements::GNDView(elementId, parent);
        }
        case Core::Circuit::ElementType::BUTTON:
        {
            return new UI::CircuitElements::PressButtonView(elementId, parent);
        }
        case Core::Circuit::ElementType::LED:
        {
            return new UI::CircuitElements::LEDView(elementId, parent);
        }
        case Core::Circuit::ElementType::BUZZER:
        {
            return new UI::CircuitElements::BuzzerView(elementId, parent);
        }
        case Core::Circuit::ElementType::AND_GATE:
        {
            return new UI::CircuitElements::ANDGateView(elementId, parent);
        }
        case Core::Circuit::ElementType::OR_GATE:
        {
            return new UI::CircuitElements::ORGateView(elementId, parent);
        }
        case Core::Circuit::ElementType::NOT_GATE:
        {
            return new UI::CircuitElements::NOTGateView(elementId, parent);
        }
        case Core::Circuit::ElementType::UNKNOWN:
        default:
            break;
        }
        int unknownElementTypeIdentifier = -1;
        return new UI::CircuitElements::ElementView(type, 0, 0, unknownElementTypeIdentifier, parent);
    }
}
