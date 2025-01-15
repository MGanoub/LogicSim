#ifndef VCCVIEW_H
#define VCCVIEW_H

#include "UI/disp/Widgets/CircuitElement/elementView.h"

namespace UI::CircuitElements
{
    class VCCView : public ElementView
    {
    public:
        VCCView(int elementId, QGraphicsItem *parent = nullptr);
        void setVisualState(Core::Circuit::State state) override;
    };
}
#endif // VCCVIEW_H
