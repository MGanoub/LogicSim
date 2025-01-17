#include "pressButtonView.h"

namespace UI::CircuitElements
{
    PressButtonView::PressButtonView(int elementId, QGraphicsItem *parent)
        : ElementView(Core::Circuit::ElementType::BUTTON, 0, 1, elementId, parent)
    {
        setVisualState(Core::Circuit::State::OFF);
        m_isPressable = true;
    }

    void PressButtonView::setVisualState(Core::Circuit::State state)
    {
        switch (state)
        {
        case Core::Circuit::State::ON:
        {
            setPixmap(m_resourceInfo.OnStatePixmapPath);
            break;
        }
        case Core::Circuit::State::OFF:
        {
            setPixmap(m_resourceInfo.offStatePixmapPath);
            break;
        }
        default:
            break;
        }
        update();
    }
}
