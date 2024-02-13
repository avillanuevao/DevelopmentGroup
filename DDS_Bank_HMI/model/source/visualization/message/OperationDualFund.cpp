#include "OperationDualFund.hpp"

namespace model
{
namespace visualization
{
namespace message
{

OperationDualFund::OperationDualFund(model::visualization::message::OperationType operationType,
                                     int amount,
                                     model::operations::FundType originFund,
                                     model::operations::FundType destinationFund):
    model::visualization::message::OperationInterface(operationType, amount, originFund),
    m_destinationFund(destinationFund)
{

}

std::string OperationDualFund::toString()
{
    std::string sFundOrigin = m_fundType._to_string();
    std::string sFundDestination = m_destinationFund._to_string();
    std::string sAmount = std::to_string(m_amount);

    return "The transfer has been completed from the " + sFundOrigin + " fund to the " + sFundDestination + " fund with an amount of " + sAmount + ".";
}

}
}
}
