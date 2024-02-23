#include "SelectFund.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

SelectFund::SelectFund()
{

}

void SelectFund::selectFund(model::operations::kFundType fundType)
{
  frontend::viewModel::ui::operations::signal::SelectFund signal(fundType);

  notifySubscribers(signal);
}

}  // namespace operations
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend
