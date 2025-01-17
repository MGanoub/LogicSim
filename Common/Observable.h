#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "Common/IObservable.h"
#include "Common/IObserver.h"
#include <vector>

namespace Common
{

    class Observable : public IObservable
    {
    public:
        Observable() = default;
        void notifyListeners() override;
        void addListenser(IObserver *observer) override;

    private:
        std::vector<IObserver *> m_listeners;
    };
}
#endif // OBSERVABLE_H
