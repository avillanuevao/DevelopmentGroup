#include "VisualizeFundViewModel.hpp"

namespace frontend
{
namespace viewModel
{
namespace  ui
{
namespace visualization
{


VisualizeFundViewModel::VisualizeFundViewModel()
{

}

void VisualizeFundViewModel::updateView(int amount)
{
    frontend::viewModel::ui::visualization::signal::VisualizeFundSignal signal(amount);
    notifySubscribers(signal);
}

}
}
}
}
