#ifndef ORGATEVIEW_H
#define ORGATEVIEW_H

#include "UI/disp/Widgets/CircuitElement/elementView.h"

namespace UI::CircuitElements
{
    class ORGateView : public ElementView
    {
    public:
        ORGateView(int elementId, QGraphicsItem *parent = nullptr);
        void setVisualState(Core::Circuit::State state) override;
    };
}

#endif // ORGATEVIEW_H
