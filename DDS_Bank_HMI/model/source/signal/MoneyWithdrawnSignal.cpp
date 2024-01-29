#include <signal/MoneyWithdrawnSignal.hpp>

namespace model
{
namespace signal
{

MoneyWithdrawnSignal::MoneyWithdrawnSignal(model::FundType fundType, int amount)
    : m_fundType(fundType), m_amount(amount)
{
}

int MoneyWithdrawnSignal::getAmount() const
{
    return m_amount;
}

void MoneyWithdrawnSignal::setAmount(int newAmount)
{
    m_amount = newAmount;
}

model::FundType MoneyWithdrawnSignal::getFundType() const
{
    return m_fundType;
}

void MoneyWithdrawnSignal::setFundType(model::FundType newFundType)
{
    m_fundType = newFundType;
}

}
}
