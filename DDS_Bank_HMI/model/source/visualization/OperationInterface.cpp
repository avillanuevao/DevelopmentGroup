#include "OperationInterface.hpp"

namespace model
{
namespace visualization
{

OperationInterface::OperationInterface(model::visualization::OperationType operationType,
                                       int amount,
                                       model::operations::FundType fundType):
    m_operationType(operationType),
    m_amount(amount),
    m_fundType(fundType)
{

}


}
}
