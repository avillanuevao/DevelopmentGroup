#ifndef MODEL_VISUALIZATION_MESSAGE_ALLMESSAGES_HPP
#define MODEL_VISUALIZATION_MESSAGE_ALLMESSAGES_HPP

#include <visualization/message/AllMessagesInterface.hpp>

namespace model
{
namespace visualization
{
namespace message
{

class AllMessages :
        public model::visualization::message::AllMessagesInterface
{
    public:
        AllMessages();

        void addMessage(model::visualization::message::MessageInterface newMessage) override;
};

}
}
}

#endif // MODEL_VISUALIZATION_MESSAGE_ALLMESSAGES_HPP
