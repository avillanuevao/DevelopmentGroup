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

    // Hay codigo duplicado porque hacen la misma funcionalidad, que en este caso es setear el valor de la variable
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

void Fund::setAmount(int newAmount) noexcept(false)
{
    if(newAmount < 0)
    {
        throw std::logic_error("Amount must be positive");
    }

    m_amount = newAmount;
}

}

