#include "DepositMoney.hpp"

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

    sendShowMessageSignal(model::visualization::message::kMessageType::Success, amount);
  }
  catch (std::logic_error e)
  {
    sendShowMessageSignal(model::visualization::message::kMessageType::Failure, amount);

    std::cerr << e.what() << std::endl;
  }
}

void DepositMoney::sendShowMessageSignal(model::visualization::message::kMessageType messageType, int amount)
{
  std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

  backend::controller::operations::signal::ShowMessage signal(date, messageType,
                                                              model::visualization::message::kOperationType::Deposit,
                                                              amount, mFundGetParameter->getFundType());

  notifySubscribers(signal);
}

}  // namespace operations
}  // namespace controller
}  // namespace backend

