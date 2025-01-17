#ifndef PRESSBUTTONVIEW_H
#define PRESSBUTTONVIEW_H

#include "UI/disp/Widgets/CircuitElement/elementView.h"

namespace UI::CircuitElements
{
    class PressButtonView : public ElementView
    {
    public:
        PressButtonView(int elementId, QGraphicsItem *parent = nullptr);
        void setVisualState(Core::Circuit::State state) override;
    };
}
#endif // PRESSBUTTONVIEW_H
