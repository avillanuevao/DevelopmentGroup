#ifndef MODEL_VISUALIZATION_MESSAGE_ALLMESSAGESINTERFACE_HPP
#define MODEL_VISUALIZATION_MESSAGE_ALLMESSAGESINTERFACE_HPP

#include<visualization/message/MessageInterface.hpp>

namespace model
{
namespace visualization
{
namespace message
{

class AllMessagesInterface
{
    public:
        AllMessagesInterface();

        virtual void addMessage(model::visualization::MessageInterface newMessage) = 0;
};

}
}
}

#endif // MODEL_VISUALIZATION_MESSAGE_ALLMESSAGESINTERFACE_HPP
