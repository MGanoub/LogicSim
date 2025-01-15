#ifndef ANDGATEVIEW_H
#define ANDGATEVIEW_H

#include "UI/disp/Widgets/CircuitElement/elementView.h"

namespace UI::CircuitElements
{
    class ANDGateView : public ElementView
    {
    public:
        ANDGateView(int elementId, QGraphicsItem *parent = nullptr);
        void setVisualState(Core::Circuit::State state) override;
    };
}
#endif // ANDGATEVIEW_H
