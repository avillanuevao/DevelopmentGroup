#include "VisualizeFundViewModel.hpp"

namespace frontend
{
namespace viewModel
{
namespace  ui
{
namespace visualization
{


VisualizeFundViewModel::VisualizeFundViewModel(std::shared_ptr<model::operations::iFundGetParameters> fund):
    m_fund(fund)
{

}

void VisualizeFundViewModel::updateView(model::operations::kFundType fundType, int amount)
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
    model::operations::kFundType fundType = m_fund->getFundType();
    updateView(fundType, amount);
}

}
}
}
}
