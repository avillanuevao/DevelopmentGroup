#include "MessageInterface.hpp"

namespace model
{
namespace visualization
{
namespace message
{

MessageInterface::MessageInterface(time_t date,
                                   model::visualization::message::MessageType messageType,
                                   model::visualization::message::OperationType operationType,
                                   model::operations::FundType fundOrigin,
                                   model::operations::FundType fundDestination,
                                   int amount):
    m_date(date),
    m_messageType(messageType)
{
    if(operationType == +model::visualization::message::OperationType::TRANSFER)
    {
        m_operation = std::unique_ptr<model::visualization::message::OperationInterface>(
                    new model::visualization::message::OperationDualFund(operationType, amount, fundOrigin, fundDestination));
    }
    else
    {
        m_operation = std::unique_ptr<model::visualization::message::OperationInterface>(
                    new model::visualization::message::OperationSingleFund(operationType, amount, fundOrigin));
    }
}


}
}
}
