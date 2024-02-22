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

void AllMessages::addMessage(aMessage newMessage)
{
  mAllMessages.push_back(newMessage);

  model::visualization::message::signal::ShowMessage signal(newMessage);

  notifySubscribers(signal);
}

}  // namespace message
}  // namespace visualization
}  // namespace model
