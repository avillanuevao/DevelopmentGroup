#include "WithdrawnMoneySignal.hpp"

namespace frontend
{
namespace viewModel
{
namespace signal
{

WithdrawnMoneySignal::WithdrawnMoneySignal(model::FundType fundType,  int amount):
    m_fundType(fundType),
    m_amount(amount)
{

}

model::FundType WithdrawnMoneySignal::getFundType() const
{
    return m_fundType;
}

int WithdrawnMoneySignal::getAmount() const
{
    return m_amount;
}

}
}
}
