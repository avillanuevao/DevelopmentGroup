#include "Deposit.hpp"

namespace model {
Deposit::Deposit(FundType fundType, int amount): m_fundType(fundType), m_amount(amount)
{

}

FundType Deposit::getFundType() const
{
    return m_fundType;
}

void Deposit::setFundType(FundType newFundType)
{
    m_fundType = newFundType;
}

int Deposit::getAmount() const
{
    return m_amount;
}

void Deposit::setAmount(int newAmount)
{
    m_amount = newAmount;
}

}
