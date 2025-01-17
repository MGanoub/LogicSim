#include "Observable.h"

namespace Common
{
    void Observable::addListenser(Common::IObserver *observer)
    {
        m_listeners.push_back(observer);
    }

    void Observable::notifyListeners()
    {
        for (auto &listenser : m_listeners)
        {
            listenser->circuitChanged();
        }
    }
}
