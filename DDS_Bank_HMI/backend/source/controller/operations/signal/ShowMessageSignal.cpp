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
                                     model::visualization::message::kMessageType messageType,
                                     model::visualization::message::kOperationType operationType,
                                     int amount,
                                     model::operations::kFundType originFundType,
                                     model::operations::kFundType destinationFundType) :
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

const model::visualization::message::kMessageType &ShowMessageSignal::getMessageType() const
{
    return m_messageType;
}

const model::visualization::message::kOperationType &ShowMessageSignal::getOperationType() const
{
    return m_operationType;
}

int ShowMessageSignal::getAmount() const
{
    return m_amount;
}

const model::operations::kFundType &ShowMessageSignal::getOriginFundType() const
{
    return m_originFundType;
}

const model::operations::kFundType &ShowMessageSignal::getDestinationFundType() const
{
    return m_destinationFundType;
}


}
}
}
}
