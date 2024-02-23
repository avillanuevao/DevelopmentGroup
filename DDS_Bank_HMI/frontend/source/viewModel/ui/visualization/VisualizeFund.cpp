#include "VisualizeFund.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace visualization
{

VisualizeFund::VisualizeFund(std::shared_ptr<model::operations::iFundGetParameters> fund):
  mFund(fund)
{

}

void VisualizeFund::updateView()
{
  int amount = mFund->getAmount();
  model::operations::kFundType fundType = mFund->getFundType();

  updateView(fundType, amount);
}

void VisualizeFund::updateView(model::operations::kFundType fundType, int amount)
{
  if(fundType == mFund->getFundType())
  {
    frontend::viewModel::ui::visualization::signal::VisualizeFund signal(amount);

    notifySubscribers(signal);
  }
}

}  // namespace visualization
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend
