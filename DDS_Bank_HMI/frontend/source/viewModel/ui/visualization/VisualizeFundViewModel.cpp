#include "VisualizeFundViewModel.hpp"

namespace frontend
{
namespace viewModel
{
namespace  ui
{
namespace visualization
{


VisualizeFundViewModel::VisualizeFundViewModel(std::shared_ptr<model::operations::FundGetParametersInterface> fund):
    m_fund(fund)
{

}

void VisualizeFundViewModel::updateView(model::operations::FundType fundType, int amount)
{
    if(fundType == m_fund->getFundType())
    {
        frontend::viewModel::ui::visualization::signal::VisualizeFundSignal signal(amount);
        notifySubscribers(signal);
    }
}

void VisualizeFundViewModel::updateView()
{
    int amount = m_fund->getAmount();
    model::operations::FundType fundType = m_fund->getFundType();
    updateView(fundType, amount);
}

}
}
}
}
