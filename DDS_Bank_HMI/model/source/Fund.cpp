#include "Fund.hpp"

namespace model {

Fund::Fund(model::FundType fundType, int amount) : m_fundType(fundType), m_amount(amount)
{

}

void Fund::increaseAmount(int amount) noexcept(false)
{
    if(amount < 0)
    {
        throw std::logic_error("Amount must be positive");
    }

    m_amount += amount;
}

void Fund::decreaseAmount(int amount)
{
    if(amount < 0)
    {
        throw std::logic_error("Amount must be positive");
    }

    if(amount > m_amount)
    {
        throw std::logic_error("Not enough money");
    }

    m_amount -= amount;

}

model::FundType Fund::getFundType() const
{
    return m_fundType;
}

int Fund::getAmount() const
{
    return m_amount;
}

void Fund::setAmount(int newAmount) noexcept(false)
{
    if(newAmount < 0)
    {
        throw std::logic_error("Amount must be positive");
    }

    m_amount = newAmount;
}

}

