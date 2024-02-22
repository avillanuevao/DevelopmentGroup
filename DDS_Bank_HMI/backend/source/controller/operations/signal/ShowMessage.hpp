#ifndef BACKEND_CONTROLLER_OPERATIONS_SIGNAL_SHOWMESSAGE_HPP
#define BACKEND_CONTROLLER_OPERATIONS_SIGNAL_SHOWMESSAGE_HPP

#include <chrono>

#include <model/source/operations/kFundType.hpp>
#include <model/source/visualization/message/kMessageType.hpp>
#include <model/source/visualization/message/kOperationType.hpp>

namespace backend
{
namespace controller
{
namespace operations
{
namespace signal
{

class ShowMessage
{
  public:
    ShowMessage(std::time_t date, model::visualization::message::kMessageType messageType,
                      model::visualization::message::kOperationType operationType, int amount,
                      model::operations::kFundType originFundType,
                      model::operations::kFundType destinationFundType = model::operations::kFundType::None);

    std::time_t getDate() const;
    model::visualization::message::kMessageType getMessageType() const;
    model::visualization::message::kOperationType getOperationType() const;
    int getAmount() const;
    model::operations::kFundType getOriginFundType() const;
    model::operations::kFundType getDestinationFundType() const;

  private:
    std::time_t mDate;
    model::visualization::message::kMessageType mMessageType;
    model::visualization::message::kOperationType mOperationType;
    int mAmount;
    model::operations::kFundType mOriginFundType;
    model::operations::kFundType mDestinationFundType;
};

}  // namespace signal
}  // namespace operations
}  // namespace controller
}  // namespace backend

#endif // BACKEND_CONTROLLER_OPERATIONS_SIGNAL_SHOWMESSAGE_HPP
