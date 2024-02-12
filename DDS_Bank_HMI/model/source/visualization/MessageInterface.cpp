#include "MessageInterface.hpp"

namespace model
{
namespace visualization
{

MessageInterface::MessageInterface(time_t date,
                                   model::visualization::MessageType messageType,
                                   model::visualization::OperationType operationType,
                                   model::operations::FundType fundOrigin,
                                   model::operations::FundType fundDestination,
                                   int amount):
    m_date(date),
    m_messageType(messageType)
{
    if(operationType == +model::visualization::OperationType::TRANSFER)
    {
        m_operation = std::unique_ptr<model::visualization::OperationInterface>(new model::visualization::OperationDualFund(operationType, amount, fundOrigin, fundDestination));
    }
    else
    {
        m_operation = std::unique_ptr<model::visualization::OperationInterface>(new model::visualization::OperationSingleFund(operationType, amount, fundOrigin));
    }
}


}
}
