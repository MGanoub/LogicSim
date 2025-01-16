#ifndef ELEMENTTYPEENUM_H
#define ELEMENTTYPEENUM_H

namespace Core::Circuit
{
    enum class ElementType
    {
        UNKNOWN,
        VCC,
        GND,
        BUTTON,
        LED,
        AND_GATE,
        OR_GATE,
        MAXITEM
    };

    enum class State
    {
        OFF = 0,
        ON = 1
    };
}

#endif // ELEMENTTYPEENUM_H
