#include "MoneyDepositedSignal.hpp"

// Try to push in the Ana Repository

namespace model {

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
