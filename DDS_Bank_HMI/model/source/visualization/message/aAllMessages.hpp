#ifndef MODEL_VISUALIZATION_MESSAGE_AALLMESSAGES_HPP
#define MODEL_VISUALIZATION_MESSAGE_AALLMESSAGES_HPP

#include <vector>

#include <designPattern/SignalPublisher.hpp>
#include <visualization/message/aMessage.hpp>
#include <visualization/message/signal/ShowMessage.hpp>

namespace model
{
namespace visualization
{
namespace message
{

class aAllMessages :
    public utils::designPattern::SignalPublisher<model::visualization::message::signal::ShowMessage>
{
  public:
    aAllMessages() = default;

    virtual void addMessage(model::visualization::message::aMessage newMessage) = 0;

  protected:
    std::vector<model::visualization::message::aMessage> mAllMessages;
};

}  // namespace message
}  // namespace visualization
}  // namespace model

#endif // MODEL_VISUALIZATION_MESSAGE_AALLMESSAGES_HPP
