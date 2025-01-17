#ifndef BUZZERVIEW_H
#define BUZZERVIEW_H

#include "UI/disp/Widgets/CircuitElement/elementView.h"
#include <QSoundEffect>

namespace UI::CircuitElements
{
    class BuzzerView : public ElementView
    {
    public:
        BuzzerView(int elementId, QGraphicsItem *parent = nullptr);

        void setVisualState(Core::Circuit::State state) override;
        void setAudioState(Core::Circuit::State state) override;

    private:
        QSoundEffect m_audio;
    };
}
#endif // BUZZERVIEW_H
