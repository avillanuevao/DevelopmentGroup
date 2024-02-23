#include "ShowMessage.hpp"

namespace backend
{
namespace view
{
namespace includeView
{
namespace visualization
{

ShowMessage::ShowMessage(std::shared_ptr<controller::visualization::ShowMessage> showMessageController) :
  mShowMessageController(showMessageController)
{

}

void ShowMessage::recievedSignal(controller::operations::signal::ShowMessage signal)
{
  mShowMessageController->addMessage(signal.getDate(), signal.getMessageType(), signal.getOperationType(),
                                     signal.getAmount(), signal.getOriginFundType(),
                                     signal.getDestinationFundType());
}

}  // namespace visualization
}  // namespace includeView
}  // namespace view
}  // namespace backend
