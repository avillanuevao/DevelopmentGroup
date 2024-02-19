#include "ShowMessageSignal.hpp"

namespace backend
{
namespace controller
{
namespace operations
{
namespace signal
{


ShowMessageSignal::ShowMessageSignal(time_t date,
                                     model::visualization::message::MessageType messageType,
                                     model::visualization::message::OperationType operationType,
                                     int amount,
                                     model::operations::FundType originFundType,
                                     model::operations::FundType destinationFundType) :
    m_date(date),
    m_messageType(messageType),
    m_operationType(operationType),
    m_amount(amount),
    m_originFundType(originFundType),
    m_destinationFundType(destinationFundType)
{

}

std::time_t ShowMessageSignal::getDate() const
{
    return m_date;
}

const model::visualization::message::MessageType &ShowMessageSignal::getMessageType() const
{
    return m_messageType;
}

const model::visualization::message::OperationType &ShowMessageSignal::getOperationType() const
{
    return m_operationType;
}

int ShowMessageSignal::getAmount() const
{
    return m_amount;
}

const model::operations::FundType &ShowMessageSignal::getOriginFundType() const
{
    return m_originFundType;
}

const model::operations::FundType &ShowMessageSignal::getDestinationFundType() const
{
    return m_destinationFundType;
}


}
}
}
}
