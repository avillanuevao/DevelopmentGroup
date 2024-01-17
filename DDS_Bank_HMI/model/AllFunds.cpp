#include "AllFunds.hpp"

namespace model {

AllFunds::AllFunds()
{
    m_funds.insert(std::make_pair<model::FundType, Fund>(
                       model::FundType::SAVINGS, model::Fund(model::FundType::SAVINGS, 0)));
    m_funds.insert(std::make_pair<model::FundType, Fund>(
                       model::FundType::HOUSING, model::Fund(model::FundType::HOUSING, 0)));
}

void AllFunds::increaseAmount(model::FundType fundType, int amount)
{
    m_funds.find(fundType)->second.increaseAmount(amount);
    model::signal::MoneyDepositedSignal signal =
            model::signal::MoneyDepositedSignal(fundType, m_funds.find(fundType)->second.getAmount());
    notifySubscribers(signal);
}

int AllFunds::getAmount(model::FundType fundType) const
{
    return m_funds.find(fundType)->second.getAmount();
}

void AllFunds::setAmount(model::FundType fundType, int newAmount)
{
    m_funds.find(fundType)->second.setAmount(newAmount);
    model::signal::MoneyDepositedSignal signal =
            model::signal::MoneyDepositedSignal(fundType, m_funds.find(fundType)->second.getAmount());
    notifySubscribers(signal);
}

}


