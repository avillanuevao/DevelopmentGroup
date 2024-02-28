#include "TransferMoney.hpp"

using ShowMessageSignal = backend::controller::operations::signal::ShowMessage;
using SaveFundSignal = backend::controller::operations::signal::SaveFund;
using ShowMessageSignalPublisher = utils::designPattern::SignalPublisher<ShowMessageSignal>;
using SaveFundSignalPublisher = utils::designPattern::SignalPublisher<SaveFundSignal>;
using kMessageType = model::visualization::message::kMessageType;
using kOperationType = model::visualization::message::kOperationType;

namespace  backend
{
namespace  controller
{
namespace  operations
{

TransferMoney::TransferMoney(std::shared_ptr<model::operations::iFundTransferAmount> fundTransferAmount,
                             std::shared_ptr<model::operations::iFundGetParameters> fundGetParameter) :
  mFundTransferAmount(fundTransferAmount), mFundGetParameter(fundGetParameter)
{

}

void TransferMoney::transfer(model::operations::kFundType destinationFundType, int amount)
{
  try
  {
    mFundTransferAmount->transferAmount(destinationFundType, amount);

    sendShowMessageSignal(kMessageType::Success, amount, destinationFundType);
    sendSaveFundSignal(mFundGetParameter->getFundType());
    sendSaveFundSignal(destinationFundType);
  }
  catch (std::logic_error e)
  {
    std::cerr << e.what() << std::endl;

    sendShowMessageSignal(kMessageType::Failure, amount, destinationFundType);
  }
}

void TransferMoney::sendShowMessageSignal(model::visualization::message::kMessageType messageType, int amount,
                                          model::operations::kFundType destinationFundType)
{
  std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

  ShowMessageSignal signal(date, messageType, kOperationType::Transfer, amount,
                           mFundGetParameter->getFundType(), destinationFundType);

  ShowMessageSignalPublisher::notifySubscribers(signal);
}

void TransferMoney::sendSaveFundSignal(model::operations::kFundType fundChanged)
{
  SaveFundSignal signal(fundChanged);

  SaveFundSignalPublisher::notifySubscribers(signal);
}

}  // namespace operations
}  // namespace controller
}  // namespace backend
