#ifndef NOTGATEVIEW_H
#define NOTGATEVIEW_H

#include "UI/disp/Widgets/CircuitElement/elementView.h"

namespace UI::CircuitElements
{
    class NOTGateView : public ElementView
    {
    public:
        NOTGateView(int elementId, QGraphicsItem *parent = nullptr);
        void setVisualState(Core::Circuit::State state) override;
    };
}

#endif // NOTGATEVIEW_H
