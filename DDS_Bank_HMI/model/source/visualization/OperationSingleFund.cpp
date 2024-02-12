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
    std::string sFund = m_fundType._to_string();
    std::string sAmount = std::to_string(m_amount);
    std::string completeMessage = "An amount of " + sAmount + " has been ";


    if(m_operationType == +model::visualization::OperationType::DEPOSIT)
    {
        completeMessage += " deposited ";
    }
    else if(m_operationType == +model::visualization::OperationType::WITHDRAW)
    {
        completeMessage += " withdrawn ";
    }
    else
    {
        return "";
    }

    completeMessage += "from the fund " + sFund + ".";

    return completeMessage;
}

}
}
