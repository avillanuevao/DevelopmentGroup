#ifndef MODEL_VISUALIZATION_MESSAGE_ALLMESSAGES_HPP
#define MODEL_VISUALIZATION_MESSAGE_ALLMESSAGES_HPP

#include <designPattern/SignalPublisher.hpp>
#include <visualization/message/aAllMessages.hpp>
#include <visualization/message/aMessage.hpp>
#include <visualization/message/signal/ShowMessage.hpp>

namespace model
{
namespace visualization
{
namespace message
{

class AllMessages :
    public model::visualization::message::aAllMessages
{
  public:
    AllMessages();

    void addMessage(model::visualization::message::aMessage newMessage) override;
};

}  // namespace message
}  // namespace visualization
}  // namespace model

#endif // MODEL_VISUALIZATION_MESSAGE_ALLMESSAGES_HPP
