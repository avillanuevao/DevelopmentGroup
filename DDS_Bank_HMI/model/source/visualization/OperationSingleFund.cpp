#include "OperationSingleFund.hpp"

namespace model
{
namespace visualization
{

OperationSingleFund::OperationSingleFund(model::visualization::OperationType operationType,
                                         int amount,
                                         model::operations::FundType fundType):
    model::visualization::OperationInterface(operationType, amount, fundType)
{

}

std::string OperationSingleFund::toString()
{
    return "";
}

}
}
