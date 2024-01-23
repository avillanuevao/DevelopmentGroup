#include "MoneyDepositedSignal.hpp"

namespace model
{
namespace signal
{

MoneyDepositedSignal::MoneyDepositedSignal(model::FundType fundType, int amount)
    : m_fundType(fundType), m_amount(amount)
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

model::FundType MoneyDepositedSignal::getFundType() const
{
    return m_fundType;
}

void MoneyDepositedSignal::setFundType(model::FundType newFundType)
{
    m_fundType = newFundType;
}

}
}
