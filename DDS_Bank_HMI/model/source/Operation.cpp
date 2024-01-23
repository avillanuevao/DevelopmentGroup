#include "Operation.hpp"

namespace model{

Operation::Operation(FundType fundTypeOrigin, FundType fundTypeDestination, int amount):
    m_fundTypeOrigin(fundTypeOrigin),
    m_fundTypeDestination(fundTypeDestination),
    m_amount(amount)
{

}

model::FundType Operation::getFundTypeOrigin() const
{
    return m_fundTypeOrigin;
}

void Operation::setFundTypeOrigin(model::FundType newFundTypeOrigin)
{
    m_fundTypeOrigin = newFundTypeOrigin;
}

model::FundType Operation::getFundTypeDestination() const
{
    return m_fundTypeDestination;
}

void Operation::setFundTypeDestination(model::FundType newFundTypeDestination)
{
    m_fundTypeDestination = newFundTypeDestination;
}

int Operation::getAmount() const
{
    return m_amount;
}

void Operation::setAmount(int newAmount)
{
    m_amount = newAmount;
}

}
