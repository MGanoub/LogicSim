#ifndef GNDVIEW_H
#define GNDVIEW_H

#include "UI/disp/Widgets/CircuitElement/elementView.h"

namespace UI::CircuitElements
{
    class GNDView : public ElementView
    {
    public:
        GNDView(int elementId, QGraphicsItem *parent = nullptr);
        void setVisualState(Core::Circuit::State state) override;
    };
}

#endif // GNDVIEW_H
