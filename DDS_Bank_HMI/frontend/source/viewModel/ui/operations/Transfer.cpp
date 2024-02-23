#include "Transfer.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

Transfer::Transfer()
{

}

void Transfer::transferMoney(model::operations::kFundType destinationFundType, int amount)
{
    frontend::viewModel::ui::operations::signal::TransferedMoney transferedMoneySignal(destinationFundType,
                                                                                       amount);

    notifySubscribers(transferedMoneySignal);
}

}  // namespace operations
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend
