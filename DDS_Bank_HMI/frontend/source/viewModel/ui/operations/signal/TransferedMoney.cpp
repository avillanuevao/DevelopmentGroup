#include "TransferedMoney.hpp"

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

TransferedMoney::TransferedMoney(model::operations::kFundType destinationFundType, int amount) :
  mDestinationFundType(destinationFundType), mAmount(amount)
{

}

model::operations::kFundType TransferedMoney::getDestinationFundType() const
{
  return mDestinationFundType;
}

int TransferedMoney::getAmount() const
{
  return mAmount;
}

}  // namespace signal
}  // namespace operations
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend
