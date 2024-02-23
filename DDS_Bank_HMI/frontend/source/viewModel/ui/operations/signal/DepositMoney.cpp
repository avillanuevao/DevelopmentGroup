#include "DepositMoney.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{
namespace signal
{

DepositMoney::DepositMoney(int amount):
  mAmount(amount)
{

}

int DepositMoney::getAmount() const
{
  return mAmount;
}

}  // namespace signal
}  // namespace operations
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend
