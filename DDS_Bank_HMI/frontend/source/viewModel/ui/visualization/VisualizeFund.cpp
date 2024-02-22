#include "VisualizeFund.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace visualization
{

VisualizeFundViewModel::VisualizeFundViewModel(std::shared_ptr<model::operations::iFundGetParameters> fund):
  mFund(fund)
{

}

void VisualizeFundViewModel::updateView(model::operations::kFundType fundType, int amount)
{
  if(fundType == mFund->getFundType())
  {
    frontend::viewModel::ui::visualization::signal::VisualizeFund signal(amount);

    notifySubscribers(signal);
  }
}

void VisualizeFundViewModel::updateView()
{
  int amount = mFund->getAmount();
  model::operations::kFundType fundType = mFund->getFundType();

  updateView(fundType, amount);
}

}  // namespace visualization
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend
