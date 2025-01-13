#include "component.h"

namespace Core::Circuit
{
    Component::Component()
    {
        static int s_uniqueIdentifier = 0;
        m_identifier = s_uniqueIdentifier++;
    }

    int Component::getIndentifier()
    {
        return m_identifier;
    }
}