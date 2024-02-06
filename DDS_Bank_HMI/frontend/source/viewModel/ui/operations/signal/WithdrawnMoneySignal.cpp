#include "WithdrawnMoneySignal.hpp"

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

WithdrawnMoneySignal::WithdrawnMoneySignal(int amount) :
    m_amount(amount)
{

}

int WithdrawnMoneySignal::getAmount() const
{
    return m_amount;
}

}
}
}
}
}
