#include "TransferedMoneySignal.hpp"

namespace frontend
{
namespace viewModel
{
namespace signal
{

TransferedMoneySignal::TransferedMoneySignal(model::FundType originFundType, model::FundType destinationFundType, int amount) :
    m_originFundType(originFundType),
    m_destinationFundType(destinationFundType),
    m_amount(amount)
{

}

model::FundType TransferedMoneySignal::getOriginFundType() const
{
    return m_originFundType;
}

void TransferedMoneySignal::setOriginFundType(model::FundType newOriginFundType)
{
    m_originFundType = newOriginFundType;
}

model::FundType TransferedMoneySignal::getDestinationFundType() const
{
    return m_destinationFundType;
}

void TransferedMoneySignal::setDestinationFundType(model::FundType newDestinationFundType)
{
    m_destinationFundType = newDestinationFundType;
}

int TransferedMoneySignal::getAmount() const
{
    return m_amount;
}

void TransferedMoneySignal::setAmount(int newAmount)
{
    m_amount = newAmount;
}

}
}
}
