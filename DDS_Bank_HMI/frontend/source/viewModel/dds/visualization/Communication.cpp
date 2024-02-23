#include "Communication.hpp"

namespace frontend
{
namespace viewModel
{
namespace dds
{
namespace visualization
{

Communication::Communication(std::shared_ptr<model::visualization::message::aAllMessages> allMessageInterface) :
    mAllMessage(allMessageInterface)
{

}

void Communication::addMessage(model::visualization::message::aMessage message)
{
    mAllMessage->addMessage(message);
}

}  // namespace operations
}  // namespace dds
}  // namespace viewModel
}  // namespace frontend
