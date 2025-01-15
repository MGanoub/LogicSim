#ifndef ELEMENTFACTORY_H
#define ELEMENTFACTORY_H

#include "Core/Circuit/elementTypeEnum.h"
#include "UI/disp/Widgets/CircuitElement/elementView.h"

namespace UI
{

    class ElementFactory
    {
    public:
        ElementFactory(ElementFactory const &) = delete;
        ElementFactory &operator=(ElementFactory const &) = delete;
        ElementFactory(ElementFactory const &&) = delete;
        ElementFactory &operator=(ElementFactory const &&) = delete;

        static ElementFactory &getInstance();
        UI::CircuitElements::ElementView *createElement(Core::Circuit::ElementType type, int elementId, QGraphicsItem *parent = nullptr);

    private:
        ElementFactory() = default;
    };
}

#endif // ELEMENTFACTORY_H
