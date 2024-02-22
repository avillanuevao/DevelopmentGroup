#include "AllFunds.hpp"

namespace model
{
namespace operations
{

AllFunds::AllFunds(model::operations::kFundType actualFund) :
  mActualFund(actualFund)
{
  initFund(model::operations::kFundType::Savings);
  initFund(model::operations::kFundType::Housing);
}

void AllFunds::increaseAmount(int amount)
{
  try
  {
    getActualFund()->increaseAmount(amount);
  }
  catch (const std::logic_error& e)
  {
    throw e;
  }

  notifySubscribersFund(mActualFund, getActualFund()->getAmount());
}

void AllFunds::decreaseAmount(int amountToDecrease)
{
  int amountActualFund = getAmount();
  int amountSavingsFund = getAmount(model::operations::kFundType::Savings);
  int amountRest = amountToDecrease - amountActualFund;
  bool isEnoughAmountInActualFund = (amountActualFund - amountToDecrease) >= 0;
  bool isEnoughAmountInSavingsFund = (amountSavingsFund - amountRest) >= 0;
  bool isActualFundSavingsFund = mActualFund == +model::operations::kFundType::Savings;

  try
  {
    if(isEnoughAmountInActualFund)
    {
      getActualFund()->decreaseAmount(amountToDecrease);
    }
    else if(isEnoughAmountInSavingsFund && !isActualFundSavingsFund)
    {
      getActualFund()->decreaseAmount(amountActualFund);
      getFund(model::operations::kFundType::Savings)->decreaseAmount(amountRest);

      notifySubscribersFund(model::operations::kFundType::Savings,
                            getFund(model::operations::kFundType::Savings)->getAmount());
    }
    else
    {
      throw std::logic_error("Amount in SAVINGS fund not enough");
    }
  }
  catch (const std::logic_error& e)
  {
    throw e;
  }

  notifySubscribersFund(mActualFund, getActualFund()->getAmount());
}

void AllFunds::transferAmount(model::operations::kFundType destinationFundType, int amount)
{
  int amountFundTypeOrigin = getActualFund()->getAmount();

  if(mActualFund == destinationFundType)
  {
    throw std::logic_error("Fund destination cant be the same as fund origin");
  }

  if(!(amountFundTypeOrigin >= amount))
  {
    throw std::logic_error("Amount to transfer cant be bigger than the amount in the fund");
  }

  try
  {
    getActualFund()->decreaseAmount(amount);
  }
  catch (const std::logic_error& e)
  {
    throw e;
  }

  try
  {
    getFund(destinationFundType)->increaseAmount(amount);
  }
  catch (const std::logic_error& e)
  {
    throw e;
  }

  notifySubscribersFund(mActualFund, getActualFund()->getAmount());
  notifySubscribersFund(destinationFundType, getFund(destinationFundType)->getAmount());

}

int AllFunds::getAmount() const
{
  return getActualFund()->getAmount();
}

int AllFunds::getAmount(model::operations::kFundType fundType) const
{
  return getFund(fundType)->getAmount();
}

model::operations::kFundType AllFunds::getFundType() const
{
  return mActualFund;
}

void AllFunds::setAmount(int newAmount)
{
  try
  {
    getActualFund()->setAmount(newAmount);
  }
  catch (const std::logic_error& e)
  {
    throw e;
  }

  notifySubscribersFund(mActualFund, getActualFund()->getAmount());
}

void AllFunds::setAmount(model::operations::kFundType fundType, int amount)
{
  try
  {
    getFund(fundType)->setAmount(amount);
  }
  catch (const std::logic_error& e)
  {
    throw e;
  }

  notifySubscribersFund(fundType, getFund(fundType)->getAmount());
}

void AllFunds::setFundType(model::operations::kFundType fundType)
{
  mActualFund = fundType;

  notifySubscribersFundType(mActualFund);
}

//std::shared_ptr<model::operations::iFund> model::operations::AllFunds::getFund(model::operations::kFundType fundType)
//{
//  return m_funds.find(fundType)->second;
//}

std::shared_ptr<model::operations::iFund> AllFunds::getFund(model::operations::kFundType fundType) const
{
  return mFunds.find(fundType)->second;
}

//std::shared_ptr<iFund> AllFunds::getActualFund()
//{
//  return getFund(mActualFund);
//}

std::shared_ptr<iFund> AllFunds::getActualFund() const
{
  return getFund(mActualFund);
}

void AllFunds::initFund(model::operations::kFundType fundType)
{
  mFunds[fundType] = std::make_shared<model::operations::Fund>(model::operations::Fund(fundType, 0));
}

void AllFunds::notifySubscribersFund(model::operations::kFundType fundType, int amount)
{
  model::operations::signal::UpdatedFund signalUpdatedModel(fundType, amount);

  utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFund>::notifySubscribers(
        signalUpdatedModel);
}

void AllFunds::notifySubscribersFundType(model::operations::kFundType fundType)
{
  model::operations::signal::UpdatedFundType signalUpdatedFundType(fundType);

  utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFundType>::notifySubscribers(
        signalUpdatedFundType);
}

}  // namespace operations
}  // namespace model
