#include "MoneyDepositedSignal.hpp"

namespace model
{
namespace signal
{

MoneyDepositedSignal::MoneyDepositedSignal(int amount) : m_amount(amount)
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

}
}
