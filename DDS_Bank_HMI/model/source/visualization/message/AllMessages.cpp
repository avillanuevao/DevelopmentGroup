#include "AllMessages.hpp"

namespace model
{
namespace visualization
{
namespace message
{

AllMessages::AllMessages()
{

}

void AllMessages::addMessage(MessageInterface newMessage)
{
    m_allMessages.push_back(newMessage);

    notifySubscribers(newMessage);
}

}
}
}
