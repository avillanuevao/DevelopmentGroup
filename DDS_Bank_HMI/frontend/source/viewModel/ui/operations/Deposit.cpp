#include "Deposit.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

Deposit::Deposit()
{

}

void Deposit::depositMoney(int amount)
{
  frontend::viewModel::ui::operations::signal::DepositMoney depositMoneySignal(amount);
  notifySubscribers(depositMoneySignal);
}

}  // namespace operations
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend
