#ifndef BACKEND_CONTROLLER_OPERATIONS_SIGNAL_SHOWMESSAGESIGNAL_HPP
#define BACKEND_CONTROLLER_OPERATIONS_SIGNAL_SHOWMESSAGESIGNAL_HPP

#include <chrono>

#include <model/source/visualization/message/MessageType.hpp>
#include <model/source/visualization/message/OperationType.hpp>
#include <model/source/operations/FundType.hpp>

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
                          model::visualization::message::MessageType messageType,
                          model::visualization::message::OperationType operationType,
                          int amount,
                          model::operations::FundType originFundType,
                          model::operations::FundType destinationFundType = model::operations::FundType::NONE);

        std::time_t getDate() const;
        const model::visualization::message::MessageType &getMessageType() const;
        int getAmount() const;
        const model::operations::FundType &getOriginFundType() const;
        const model::operations::FundType &getDestinationFundType() const;

        const model::visualization::message::OperationType &getOperationType() const;

private:
        std::time_t m_date;
        model::visualization::message::MessageType m_messageType;
        model::visualization::message::OperationType m_operationType;
        int m_amount;
        model::operations::FundType m_originFundType;
        model::operations::FundType m_destinationFundType;

};

}
}
}
}

#endif // BACKEND_CONTROLLER_OPERATIONS_SIGNAL_SHOWMESSAGESIGNAL_HPP
