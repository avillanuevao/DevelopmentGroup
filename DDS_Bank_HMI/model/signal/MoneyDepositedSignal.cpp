#include "MoneyDepositedSignal.hpp"

namespace model
{
namespace signal
{

MoneyDepositedSignal::MoneyDepositedSignal(FundType fundType, int amount) : m_fundType(fundType), m_amount(amount)
{
}

int MoneyDepositedSignal::getAmount() const
{
    return m_amount;
}

void MoneyDepositedSignal::setAmount(int newAmount)
{
    m_amount = newAmount;
}

FundType MoneyDepositedSignal::getFundType() const
{
    return m_fundType;
}

void MoneyDepositedSignal::setFundType(FundType newFundType)
{
    m_fundType = newFundType;
}

}
}
