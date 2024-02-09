#include "UpdatedFundSignal.hpp"

namespace model
{
namespace operations
{
namespace signal
{

UpdatedFundSignal::UpdatedFundSignal(model::operations::FundType fundType, int amount)
    : m_fundType(fundType), m_amount(amount)
{
}

int UpdatedFundSignal::getAmount() const
{
    return m_amount;
}

void UpdatedFundSignal::setAmount(int newAmount)
{
    m_amount = newAmount;
}

model::operations::FundType UpdatedFundSignal::getFundType() const
{
    return m_fundType;
}

void UpdatedFundSignal::setFundType(model::operations::FundType newFundType)
{
    m_fundType = newFundType;
}

}
}
}
