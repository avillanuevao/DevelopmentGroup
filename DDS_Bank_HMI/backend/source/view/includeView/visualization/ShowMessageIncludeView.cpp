#include "ShowMessageIncludeView.hpp"

namespace backend
{
namespace view
{
namespace includeView
{
namespace visualization
{


ShowMessageIncludeView::ShowMessageIncludeView(std::shared_ptr<controller::visualization::ShowMessageController> showMessageController) :
    m_showMessageController(showMessageController)
{

}

void ShowMessageIncludeView::recievedSignal(controller::operations::signal::ShowMessageSignal signal)
{
    m_showMessageController->addMessage(signal.getDate(),
                                        signal.getMessageType(),
                                        signal.getOperationType(),
                                        signal.getAmount(),
                                        signal.getOriginFundType(),
                                        signal.getDestinationFundType());
}

}
}
}
}
