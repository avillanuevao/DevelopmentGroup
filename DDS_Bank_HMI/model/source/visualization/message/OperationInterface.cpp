#include "OperationInterface.hpp"

namespace model
{
namespace visualization
{
namespace message
{

OperationInterface::OperationInterface(model::visualization::message::OperationType operationType,
                                       int amount,
                                       model::operations::FundType fundType):
    m_operationType(operationType),
    m_amount(amount),
    m_fundType(fundType)
{

}


}
}
}
