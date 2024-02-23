#include "Withdraw.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

Withdraw::Withdraw()
{

}

void Withdraw::withdrawMoney(int amount)
{
    frontend::viewModel::ui::operations::signal::WithdrawnMoney withdrawnMoneySignal(amount);

    notifySubscribers(withdrawnMoneySignal);
}

}  // namespace operations
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend
