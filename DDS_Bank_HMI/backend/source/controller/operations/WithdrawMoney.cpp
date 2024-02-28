#include <backend/source/controller/operations/WithdrawMoney.hpp>

using ShowMessageSignal = backend::controller::operations::signal::ShowMessage;
using SaveFundSignal = backend::controller::operations::signal::SaveFund;
using ShowMessageSignalPublisher = utils::designPattern::SignalPublisher<ShowMessageSignal>;
using SaveFundSignalPublisher = utils::designPattern::SignalPublisher<SaveFundSignal>;
using kMessageType = model::visualization::message::kMessageType;
using kOperationType = model::visualization::message::kOperationType;

namespace backend
{
namespace controller
{
namespace operations
{

WithdrawMoney::WithdrawMoney(std::shared_ptr<model::operations::iFundDecreaseAmount> fundDecreaseAmount,
                             std::shared_ptr<model::operations::iFundGetParameters> fundGetParameter) :
  mFundDecreaseAmount(fundDecreaseAmount), mFundGetParameters(fundGetParameter)
{

}

void WithdrawMoney::withdraw(int amount)
{
  try
  {
    mFundDecreaseAmount->decreaseAmount(amount);

    sendShowMessageSignal(kMessageType::Success, amount);
    sendSaveFundSignal(mFundGetParameters->getFundType());
    if(+mFundGetParameters->getFundType() != +model::operations::kFundType::Savings)
    {
      sendSaveFundSignal(model::operations::kFundType::Savings);
    }
  }
  catch (std::logic_error e)
  {
    sendShowMessageSignal(kMessageType::Failure, amount);

    std::cerr << e.what() << std::endl;
  }
}

void WithdrawMoney::sendShowMessageSignal(model::visualization::message::kMessageType messageType, int amount)
{
  std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

  ShowMessageSignal signal(date, messageType, kOperationType::Withdraw, amount,
                           mFundGetParameters->getFundType());

  ShowMessageSignalPublisher::notifySubscribers(signal);
}

void WithdrawMoney::sendSaveFundSignal(model::operations::kFundType fundChanged)
{
  SaveFundSignal signal(fundChanged);

  SaveFundSignalPublisher::notifySubscribers(signal);
}

}  // namespace operations
}  // namespace controller
}  // namespace backend
