#include "Fund.hpp"

namespace model
{
namespace operations
{

Fund::Fund(model::operations::kFundType fundType, int amount) :
  mFundType(fundType), mAmount(amount)
{

}

void Fund::increaseAmount(int amount)
{
  if(amount < 0)
  {
    throw std::logic_error("Amount must be positive");
  }

  setAmount(mAmount + amount);
}

void Fund::decreaseAmount(int amount)
{
  if(amount < 0)
  {
    throw std::logic_error("Amount must be positive");
  }

  try
  {
    setAmount(mAmount - amount);
  }
  catch (std::logic_error e)
  {
    throw std::logic_error("Not enough money");
  }
}

int Fund::getAmount() const
{
  return mAmount;
}

void Fund::setAmount(int newAmount)
{
  if(newAmount < 0)
  {
    throw std::logic_error("Amount must be positive");
  }

  mAmount = newAmount;
}

model::operations::kFundType Fund::getFundType() const
{
  return mFundType;
}

void Fund::setFundType(model::operations::kFundType fundType)
{
  mFundType = fundType;
}

}  // namespace operations
}  // namespace model
