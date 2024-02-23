#include "TransferMoney.hpp"

namespace  backend
{
namespace  controller
{
namespace  operations
{

TransferMoney::TransferMoney(std::shared_ptr<model::operations::iFundTransferAmount> fund,
                             std::shared_ptr<model::operations::iFundGetParameters> fundGetParameter) :
  mFund(fund),
  mFundGetParameter(fundGetParameter)
{

}

void TransferMoney::transfer(model::operations::kFundType destinationFundType, int amount)
{
  try
  {
    mFund->transferAmount(destinationFundType, amount);

    sendShowMessageSignal(model::visualization::message::kMessageType::Success, amount, destinationFundType);
  }
  catch (std::logic_error e) {
    std::cerr << e.what() << std::endl;

    sendShowMessageSignal(model::visualization::message::kMessageType::Failure, amount, destinationFundType);
  }
}

void TransferMoney::sendShowMessageSignal(model::visualization::message::kMessageType messageType, int amount,
                                          model::operations::kFundType destinationFundType)
{
  std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

  backend::controller::operations::signal::ShowMessage signal(date, messageType,
                                                              model::visualization::message::kOperationType::Transfer,
                                                              amount, mFundGetParameter->getFundType(),
                                                              destinationFundType);

  notifySubscribers(signal);
}

}  // namespace operations
}  // namespace controller
}  // namespace backend
