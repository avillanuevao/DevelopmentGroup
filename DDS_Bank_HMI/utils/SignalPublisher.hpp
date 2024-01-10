#ifndef SIGNALPUBLISHER_HPP
#define SIGNALPUBLISHER_HPP

#include <algorithm>
#include <vector>
#include <memory>
#include <utils/SignalSubscriber.hpp>   //Utilizar rutas absolutas

namespace utils {

    template <class TSignal>
    class SignalPublisher
    {
        public:
            SignalPublisher() = default;

            void addSubscriber(SignalSubscriber<TSignal>& subscriber)
            {
                m_subscribers.push_back(subscriber);
            }

            void removeSubscriber(SignalSubscriber<TSignal>& subscriber)
            {
                m_subscribers.erase(std::remove(m_subscribers.begin(), m_subscribers.end(), *subscriber), m_subscribers.end());
            }

            void notifySubscribers(TSignal signal)
            {
                for (std::reference_wrapper<SignalSubscriber<TSignal>> subscriber : m_subscribers)
                {
                    subscriber.get().update(signal);
                }
            }

        private:
            std::vector<std::reference_wrapper<SignalSubscriber<TSignal>>> m_subscribers;
    };

}
#endif // SIGNALPUBLISHER_HPP
