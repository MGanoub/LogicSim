#ifndef IOBSERVER_H
#define IOBSERVER_H

namespace Common
{
    class IObserver
    {
    public:
        virtual void circuitChanged() = 0;
    };
}
#endif // IOBSERVER_H
