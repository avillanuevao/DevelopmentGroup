#ifndef SIGNALSUBSCRIBER_HPP
#define SIGNALSUBSCRIBER_HPP

namespace utils
{
namespace designPattern
{

template <class TSignal>
class SignalSubscriber
{
    public:
        SignalSubscriber() = default;
        virtual ~SignalSubscriber(){}

        virtual void recievedSignal(TSignal signal) = 0;
};

}
}

#endif // SIGNALSUBSCRIBER_HPP
