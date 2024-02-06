#include "TransferedMoneySignal.hpp"

namespace frontend
{
namespace viewModel
{
namespace signal
{

TransferedMoneySignal::TransferedMoneySignal(model::FundType destinationFundType, int amount) :
    m_destinationFundType(destinationFundType),
    m_amount(amount)
{

}

model::FundType TransferedMoneySignal::getDestinationFundType() const
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
