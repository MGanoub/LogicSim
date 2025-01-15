#ifndef VCCVIEW_H
#define VCCVIEW_H

#include "UI/disp/Widgets/CircuitElement/elementView.h"

namespace UI::CircuitElements
{
    class VCCView : public UI::CustomWidgets::ElementView
    {
    public:
        VCCView(int elementId, QGraphicsItem *parent = nullptr);
    };
}
#endif // VCCVIEW_H
