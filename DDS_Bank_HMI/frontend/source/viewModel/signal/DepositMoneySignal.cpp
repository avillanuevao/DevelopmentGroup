#include "DepositMoneySignal.hpp"

namespace frontend
{
namespace viewModel
{
namespace signal
{

DepositMoneySignal::DepositMoneySignal(int amount):
    m_amount(amount)
{

}

int DepositMoneySignal::getAmount() const
{
    return m_amount;
}

}
}
}
