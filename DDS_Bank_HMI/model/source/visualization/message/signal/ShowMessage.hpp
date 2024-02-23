#ifndef MODEL_VISUALIZATION_MESSAGE_SIGNAL_SHOWMESSAGE_HPP
#define MODEL_VISUALIZATION_MESSAGE_SIGNAL_SHOWMESSAGE_HPP

#include <visualization/message/aMessage.hpp>

namespace model
{
namespace visualization
{
namespace message
{
namespace signal
{

class ShowMessage
{
  public:
    ShowMessage(model::visualization::message::aMessage message);

    const model::visualization::message::aMessage getMessage() const;

  private:
    model::visualization::message::aMessage mMessage;
};

}  // namespace signal
}  // namespace message
}  // namespace visualization
}  // namespace model

#endif  // MODEL_VISUALIZATION_MESSAGE_SIGNAL_SHOWMESSAGE_HPP
