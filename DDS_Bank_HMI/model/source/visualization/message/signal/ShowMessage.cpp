#include "ShowMessage.hpp"

namespace model
{
namespace visualization
{
namespace message
{
namespace signal
{

ShowMessage::ShowMessage(aMessage message) :
  mMessage(message)
{

}

const model::visualization::message::aMessage ShowMessage::getMessage() const
{
  return mMessage;
}

}  // namespace signal
}  // namespace message
}  // namespace visualization
}  // namespace model
