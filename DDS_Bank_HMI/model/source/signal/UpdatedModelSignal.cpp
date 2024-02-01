#include "UpdatedModelSignal.hpp"

namespace model
{
namespace signal
{

UpdatedModelSignal::UpdatedModelSignal(model::FundType fundType, int amount)
    : m_fundType(fundType), m_amount(amount)
{
}

int UpdatedModelSignal::getAmount() const
{
    return m_amount;
}

void UpdatedModelSignal::setAmount(int newAmount)
{
    m_amount = newAmount;
}

model::FundType UpdatedModelSignal::getFundType() const
{
    return m_fundType;
}

void UpdatedModelSignal::setFundType(model::FundType newFundType)
{
    m_fundType = newFundType;
}

}
}
