#include "ShowMessageViewModel.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace visualization
{

ShowMessageViewModel::ShowMessageViewModel()
{

}

void ShowMessageViewModel::recievedSignal(model::visualization::message::signal::ShowMessage signal)
{
    frontend::viewModel::ui::visualization::signal::ShowMessageSignal signalViewModel(signal.getMessage());

    notifySubscribers(signalViewModel);
}

}
}
}
}
