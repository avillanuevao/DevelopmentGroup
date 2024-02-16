#include "DDSViewModel.hpp"

namespace frontend
{
namespace viewModel
{
namespace dds
{
namespace visualization
{

DDSViewModel::DDSViewModel(std::shared_ptr<model::visualization::message::AllMessagesInterface> allMessageInterface) :
    m_allMessageInterface(allMessageInterface)
{

}

void DDSViewModel::addMessage(model::visualization::message::MessageInterface message)
{
    m_allMessageInterface->addMessage(message);
}

}
}
}
}
