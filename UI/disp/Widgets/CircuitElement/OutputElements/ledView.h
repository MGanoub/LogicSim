#ifndef LEDVIEW_H
#define LEDVIEW_H

#include "UI/disp/Widgets/CircuitElement/elementView.h"

namespace UI::CircuitElements
{
    class LEDView : public UI::CustomWidgets::ElementView
    {
    public:
        LEDView(int elementId, QGraphicsItem *parent = nullptr);

        void setOutputState(Core::Circuit::State state) override;
    };
}

#endif // LEDVIEW_H
