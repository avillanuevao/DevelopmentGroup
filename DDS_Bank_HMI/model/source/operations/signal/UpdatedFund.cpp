#include "UpdatedFund.hpp"

namespace model
{
namespace operations
{
namespace signal
{

UpdatedFund::UpdatedFund(model::operations::kFundType fundType, int amount) :
  mFundType(fundType), mAmount(amount)
{

}

int UpdatedFund::getAmount() const
{
  return mAmount;
}

void UpdatedFund::setAmount(int newAmount)
{
  mAmount = newAmount;
}

model::operations::kFundType UpdatedFund::getFundType() const
{
  return mFundType;
}

void UpdatedFund::setFundType(model::operations::kFundType newFundType)
{
  mFundType = newFundType;
}

}  // namespace signal
}  // namespace operations
}  // namespace model
