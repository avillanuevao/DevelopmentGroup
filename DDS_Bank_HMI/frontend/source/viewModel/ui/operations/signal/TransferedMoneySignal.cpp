#include "TransferedMoneySignal.hpp"

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

TransferedMoneySignal::TransferedMoneySignal(model::operations::FundType destinationFundType, int amount) :
    m_destinationFundType(destinationFundType),
    m_amount(amount)
{

}

model::operations::FundType TransferedMoneySignal::getDestinationFundType() const
{
    return m_destinationFundType;
}

int TransferedMoneySignal::getAmount() const
{
    return m_amount;
}

}
}
}
}
}