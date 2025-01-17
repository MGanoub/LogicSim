#include "buzzerView.h"

namespace UI::CircuitElements
{
    BuzzerView::BuzzerView(int elementId, QGraphicsItem *parent)
        : ElementView(Core::Circuit::ElementType::BUZZER, 1, 0, elementId, parent)
    {
        setVisualState(Core::Circuit::State::OFF);

        m_audio.setSource(QUrl::fromLocalFile(m_resourceInfo.audioFilePath));
        m_audio.setLoopCount(QSoundEffect::Infinite);
        setAudioState(Core::Circuit::State::OFF);
    }

    void BuzzerView::setVisualState(Core::Circuit::State state)
    {
        switch (state)
        {
        case Core::Circuit::State::ON:
        {
            setPixmap(m_resourceInfo.OnStatePixmapPath);
            break;
        }
        case Core::Circuit::State::OFF:
        {
            setPixmap(m_resourceInfo.offStatePixmapPath);
            break;
        }
        default:
            break;
        }
        update();
    }

    void BuzzerView::setAudioState(Core::Circuit::State state)
    {
        switch (state)
        {
        case Core::Circuit::State::ON:
        {
            m_audio.play();
            break;
        }
        case Core::Circuit::State::OFF:
        {
            m_audio.stop();
            break;
        }
        default:
            break;
        }
    }
}
