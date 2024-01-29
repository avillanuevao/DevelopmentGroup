#include "MoneyTransferedSignal.hpp"

namespace  model
{
namespace  signal
{

MoneyTransferedSignal::MoneyTransferedSignal(FundType fundType, int amount) :
    m_fundType(fundType),
    m_amount(amount)
{

}

model::FundType MoneyTransferedSignal::getFundType() const
{
    return m_fundType;
}

void MoneyTransferedSignal::setFundType(model::FundType newFundType)
{
    m_fundType = newFundType;
}

int MoneyTransferedSignal::getAmount() const
{
    return m_amount;
}

void MoneyTransferedSignal::setAmount(int newAmount)
{
    m_amount = newAmount;
}

}
}