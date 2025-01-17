#ifndef IOBSERVABLE_H
#define IOBSERVABLE_H

namespace Common
{
    class IObserver;
    class IObservable
    {
    public:
        virtual void notifyListeners() = 0;
        virtual void addListenser(IObserver *observer) = 0;
    };
}
#endif // IOBSERVABLE_H
