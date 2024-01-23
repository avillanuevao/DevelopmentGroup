#include "DepositMoneySignal.hpp"

namespace frontend
{
namespace viewModel
{
namespace signal
{

DepositMoneySignal::DepositMoneySignal(model::FundType fundType,  int amount):
    m_fundType(fundType),
    m_amount(amount)
{

}

model::FundType DepositMoneySignal::getFundType() const
{
    return m_fundType;
}

int DepositMoneySignal::getAmount() const
{
    return m_amount;
}

}
}
}
