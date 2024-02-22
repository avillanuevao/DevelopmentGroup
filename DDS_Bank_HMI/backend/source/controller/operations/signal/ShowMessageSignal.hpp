#ifndef BACKEND_CONTROLLER_OPERATIONS_SIGNAL_SHOWMESSAGESIGNAL_HPP
#define BACKEND_CONTROLLER_OPERATIONS_SIGNAL_SHOWMESSAGESIGNAL_HPP

#include <chrono>

#include <model/source/visualization/message/kMessageType.hpp>
#include <model/source/visualization/message/kOperationType.hpp>
#include <model/source/operations/kFundType.hpp>

namespace backend
{
namespace controller
{
namespace operations
{
namespace signal
{

class ShowMessageSignal
{
    public:
        ShowMessageSignal(std::time_t date,
                          model::visualization::message::kMessageType messageType,
                          model::visualization::message::kOperationType operationType,
                          int amount,
                          model::operations::kFundType originFundType,
                          model::operations::kFundType destinationFundType = model::operations::kFundType::None);

        std::time_t getDate() const;
        const model::visualization::message::kMessageType &getMessageType() const;
        int getAmount() const;
        const model::operations::kFundType &getOriginFundType() const;
        const model::operations::kFundType &getDestinationFundType() const;

        const model::visualization::message::kOperationType &getOperationType() const;

private:
        std::time_t m_date;
        model::visualization::message::kMessageType m_messageType;
        model::visualization::message::kOperationType m_operationType;
        int m_amount;
        model::operations::kFundType m_originFundType;
        model::operations::kFundType m_destinationFundType;

};

}
}
}
}

#endif // BACKEND_CONTROLLER_OPERATIONS_SIGNAL_SHOWMESSAGESIGNAL_HPP
