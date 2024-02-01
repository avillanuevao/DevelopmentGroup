#include "Fund.hpp"

namespace model {

Fund::Fund(model::FundType fundType, int amount) : m_fundType(fundType), m_amount(amount)
{

}

void Fund::increaseAmount(int amount)
{
    if(amount < 0)
    {
        throw std::logic_error("Amount must be positive");
    }

    setAmount(m_amount + amount);
}

void Fund::decreaseAmount(int amount)
{
    if(amount < 0)
    {
        throw std::logic_error("Amount must be positive");
    }

    try {
        setAmount(m_amount - amount);
    }  catch (std::logic_error e) {
        throw std::logic_error("Not enough money");
    }
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
    if(newAmount < 0)
    {
        throw std::logic_error("Amount must be positive");
    }

    m_amount = newAmount;
}

void Fund::setFundType(FundType fundType)
{
    m_fundType = fundType;
}

}

