#include "DepositMoney.hpp"

using ShowMessageSignal = backend::controller::operations::signal::ShowMessage;
using SaveFundSignal = backend::controller::operations::signal::SaveFund;
using ShowMessageSignalPublisher = utils::designPattern::SignalPublisher<ShowMessageSignal>;
using SaveFundSignalPublisher = utils::designPattern::SignalPublisher<SaveFundSignal>;
using kMessageType = model::visualization::message::kMessageType;
using kOperationType = model::visualization::message::kOperationType;

namespace backend
{
namespace  controller
{
namespace  operations
{

DepositMoney::DepositMoney(std::shared_ptr<model::operations::iFundIncreaseAmount> fundIncreaseAmount,
                           std::shared_ptr<model::operations::iFundGetParameters> fundGetParameter) :
  mFundIncreaseAmount(fundIncreaseAmount), mFundGetParameter(fundGetParameter)
{

}

void DepositMoney::deposit(int amount)
{
  try
  {
    mFundIncreaseAmount->increaseAmount(amount);

    sendShowMessageSignal(kMessageType::Success, amount);
    sendSaveFundSignal(mFundGetParameter->getFundType());
  }
  catch (std::logic_error e)
  {
    sendShowMessageSignal(kMessageType::Failure, amount);

    std::cerr << e.what() << std::endl;
  }
}

void DepositMoney::sendShowMessageSignal(model::visualization::message::kMessageType messageType, int amount)
{
  std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

  ShowMessageSignal signal(date, messageType, kOperationType::Deposit, amount,
                           mFundGetParameter->getFundType());

  ShowMessageSignalPublisher::notifySubscribers(signal);
}

void DepositMoney::sendSaveFundSignal(model::operations::kFundType fundChanged)
{
  SaveFundSignal signal(fundChanged);

  SaveFundSignalPublisher::notifySubscribers(signal);
}

}  // namespace operations
}  // namespace controller
}  // namespace backend
