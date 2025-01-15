#ifndef ANDGATE_H
#define ANDGATE_H

#include "UI/disp/Widgets/CircuitElement/elementView.h"

namespace UI::CircuitElements
{
    class ANDGate : public ElementView
    {
    public:
        ANDGate(int elementId, QGraphicsItem *parent = nullptr);
        void setVisualState(Core::Circuit::State state) override;
    };
}
#endif // ANDGATE_H
