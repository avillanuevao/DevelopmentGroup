#include "VisualizeFundSignal.hpp"

namespace frontend
{
namespace viewModel
{
namespace  ui
{
namespace visualization
{
namespace signal
{

VisualizeFundSignal::VisualizeFundSignal(int amount) :
    m_amount(amount)
{

}

int VisualizeFundSignal::getAmount() const
{
    return m_amount;
}

void VisualizeFundSignal::setAmount(int newAmount)
{
    m_amount = newAmount;
}

}
}
}
}
}
