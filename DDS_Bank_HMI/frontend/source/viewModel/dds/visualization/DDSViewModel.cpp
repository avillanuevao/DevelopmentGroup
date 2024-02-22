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
    mAllMessage(allMessageInterface)
{

}

void DDSViewModel::addMessage(model::visualization::message::aMessage message)
{
    mAllMessage->addMessage(message);
}

}  // namespace operations
}  // namespace dds
}  // namespace viewModel
}  // namespace frontend
