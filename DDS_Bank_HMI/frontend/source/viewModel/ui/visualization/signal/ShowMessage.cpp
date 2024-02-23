#include "ShowMessage.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace visualization
{
namespace signal
{

ShowMessage::ShowMessage(model::visualization::message::aMessage message) :
    mMessage(message)
{

}

const model::visualization::message::aMessage ShowMessage::getMessage() const
{
    return mMessage;
}

}  // namespace signal
}  // namespace visualization
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend
