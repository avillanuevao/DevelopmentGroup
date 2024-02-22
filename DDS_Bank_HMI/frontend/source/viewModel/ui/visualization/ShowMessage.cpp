#include "ShowMessage.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace visualization
{

ShowMessage::ShowMessage()
{

}

void ShowMessage::recievedSignal(model::visualization::message::signal::ShowMessage signal)
{
    frontend::viewModel::ui::visualization::signal::ShowMessage signalViewModel(signal.getMessage());

    notifySubscribers(signalViewModel);
}

}  // namespace visualization
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend
