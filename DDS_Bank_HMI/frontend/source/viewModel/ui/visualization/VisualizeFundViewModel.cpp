#include "VisualizeFundViewModel.hpp"

namespace frontend
{
namespace viewModel
{
namespace  ui
{
namespace visualization
{


VisualizeFundViewModel::VisualizeFundViewModel(std::shared_ptr<model::FundGetAmountInterface> fund):
    m_fund(fund)
{

}

void VisualizeFundViewModel::updateView(int amount)
{
    frontend::viewModel::ui::visualization::signal::VisualizeFundSignal signal(amount);
    notifySubscribers(signal);
}

void VisualizeFundViewModel::updateView()
{
    int amount = m_fund->getAmount();
    updateView(amount);
}

}
}
}
}
