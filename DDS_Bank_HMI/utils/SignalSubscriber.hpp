#ifndef SIGNALSUBSCRIBER_HPP
#define SIGNALSUBSCRIBER_HPP

namespace utils {

    template <class TSignal>
    class SignalSubscriber
    {
    public:
        SignalSubscriber() = default;
        virtual ~SignalSubscriber(){}

        virtual void update(TSignal signal) = 0;
    };

}


#endif // SIGNALSUBSCRIBER_HPP
