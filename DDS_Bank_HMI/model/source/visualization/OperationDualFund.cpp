#include "OperationDualFund.hpp"

namespace model
{
namespace visualization
{

OperationDualFund::OperationDualFund(model::visualization::OperationType operationType,
                                     int amount,
                                     model::operations::FundType originFund,
                                     model::operations::FundType destinationFund):
    model::visualization::OperationInterface(operationType, amount, originFund),
    m_destinationFund(destinationFund)
{

}

std::string OperationDualFund::toString()
{
    return "";
}

}
}
