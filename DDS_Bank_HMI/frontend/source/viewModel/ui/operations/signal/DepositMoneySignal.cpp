#include "DepositMoneySignal.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
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
}
}
