#ifndef MODEL_VISUALIZATION_MESSAGE_ALLMESSAGESINTERFACE_HPP
#define MODEL_VISUALIZATION_MESSAGE_ALLMESSAGESINTERFACE_HPP

#include <vector>

#include <visualization/message/MessageInterface.hpp>
#include <visualization/message/signal/ShowMessageSignal.hpp>
#include <designPattern/SignalPublisher.hpp>

namespace model
{
namespace visualization
{
namespace message
{

class AllMessagesInterface :
        public utils::designPattern::SignalPublisher<model::visualization::message::signal::ShowMessageSignal>
{
    public:
        AllMessagesInterface() = default;

        virtual void addMessage(model::visualization::message::MessageInterface newMessage) = 0;

    protected:
        std::vector<model::visualization::message::MessageInterface> m_allMessages;

};

}
}
}

#endif // MODEL_VISUALIZATION_MESSAGE_ALLMESSAGESINTERFACE_HPP
