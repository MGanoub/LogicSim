#ifndef COMPONENTSFACTORY_H
#define COMPONENTSFACTORY_H

#include "Core/Circuit/Components/component.h"
#include "Core/Circuit/elementTypeEnum.h"

namespace Core::Circuit
{
    class ComponentsFactory
    {
    public:
        ComponentsFactory(ComponentsFactory const &) = delete;
        ComponentsFactory &operator=(ComponentsFactory const &) = delete;
        ComponentsFactory(ComponentsFactory const &&) = delete;
        ComponentsFactory &operator=(ComponentsFactory const &&) = delete;

        static ComponentsFactory &getInstance();
        Component *createComponent(ElementType type);

    private:
        ComponentsFactory() = default;
    };
}
#endif // COMPONENTSFACTORY_H
