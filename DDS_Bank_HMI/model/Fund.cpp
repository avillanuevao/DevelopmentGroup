#include "Fund.hpp"

namespace model {

Fund::Fund(model::FundType fundType, int amount) : m_fundType(fundType), m_amount(amount)
{

}

void Fund::increaseAmount(int amount)
{
    setAmount(m_amount + amount);
}

model::FundType Fund::getFundType() const
{
    return m_fundType;
}

int Fund::getAmount() const
{
    return m_amount;
}

void Fund::setAmount(int newAmount)
{
    m_amount = newAmount;
}

}

