#include "ShowMessage.hpp"

namespace backend
{
namespace controller
{
namespace operations
{
namespace signal
{

ShowMessage::ShowMessage(time_t date, model::visualization::message::kMessageType messageType,
                         model::visualization::message::kOperationType operationType, int amount,
                         model::operations::kFundType originFundType,
                         model::operations::kFundType destinationFundType) :
  mDate(date), mMessageType(messageType), mOperationType(operationType), mAmount(amount),
  mOriginFundType(originFundType), mDestinationFundType(destinationFundType)
{

}

std::time_t ShowMessage::getDate() const
{
  return mDate;
}

model::visualization::message::kMessageType ShowMessage::getMessageType() const
{
  return mMessageType;
}

model::visualization::message::kOperationType ShowMessage::getOperationType() const
{
  return mOperationType;
}

int ShowMessage::getAmount() const
{
  return mAmount;
}

model::operations::kFundType ShowMessage::getOriginFundType() const
{
  return mOriginFundType;
}

model::operations::kFundType ShowMessage::getDestinationFundType() const
{
  return mDestinationFundType;
}

}  // namespace signal
}  // namespace operations
}  // namespace controller
}  // namespace backend
