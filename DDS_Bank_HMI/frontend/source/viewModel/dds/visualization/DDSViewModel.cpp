#include "DDSViewModel.hpp"

namespace frontend
{
namespace viewModel
{
namespace dds
{
namespace visualization
{

DDSViewModel::DDSViewModel(std::shared_ptr<model::visualization::message::aAllMessages> allMessageInterface) :
    m_allMessageInterface(allMessageInterface)
{

}

void DDSViewModel::addMessage(model::visualization::message::aMessage message)
{
    m_allMessageInterface->addMessage(message);
}

}
}
}
}
