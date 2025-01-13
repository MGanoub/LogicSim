#ifndef COMPONENT_H
#define COMPONENT_H

#include "Core/Circuit/Components/IComponent.h"

namespace Core::Circuit
{
    class Component : public IComponent
    {
    public:
        enum class Type
        {
            INPUT,
            LOGIC_GATE,
            OUTPUT
        };
        Component();

        int getIndentifier() override;
        virtual void setType(Component::Type type) = 0;
        virtual Component::Type getType() = 0;

    private:
        int m_identifier;
    };
}
#endif // COMPONENT_H
