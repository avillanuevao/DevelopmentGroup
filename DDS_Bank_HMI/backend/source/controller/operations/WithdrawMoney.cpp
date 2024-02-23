#include <backend/source/controller/operations/WithdrawMoney.hpp>

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

    sendShowMessageSignal(model::visualization::message::kMessageType::Success, amount);
  }
  catch (std::logic_error e)
  {
    sendShowMessageSignal(model::visualization::message::kMessageType::Failure, amount);

    std::cerr << e.what() << std::endl;
  }
}

void WithdrawMoney::sendShowMessageSignal(model::visualization::message::kMessageType messageType, int amount)
{
  std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

  backend::controller::operations::signal::ShowMessage signal(
        date, messageType, model::visualization::message::kOperationType::Withdraw,
        amount, mFundGetParameters->getFundType());

  notifySubscribers(signal);
}

}  // namespace operations
}  // namespace controller
}  // namespace backend
