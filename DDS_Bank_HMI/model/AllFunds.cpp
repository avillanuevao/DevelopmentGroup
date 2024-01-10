#include "AllFunds.hpp"

namespace model {

    AllFunds::AllFunds()
    {
        m_funds.insert(std::make_pair<FundType, Fund>(FundType::SAVINGS, Fund(FundType::SAVINGS, 0)));
        m_funds.insert(std::make_pair<FundType, Fund>(FundType::HOUSING, Fund(FundType::HOUSING, 0)));
    }

    void AllFunds::increaseAmount(FundType fundType, int amount)
    {
        m_funds.find(fundType)->second.increaseAmount(amount);
        model::MoneyDepositedSignal signal = model::MoneyDepositedSignal(m_funds.find(fundType)->second.getAmount());
        notifySubscribers(signal);
    }

    int AllFunds::getAmount(FundType fundType) const
    {
        return m_funds.find(fundType)->second.getAmount();
    }

    void AllFunds::setAmount(FundType fundType, int newAmount)
    {
        m_funds.find(fundType)->second.setAmount(newAmount);
        model::MoneyDepositedSignal signal = model::MoneyDepositedSignal(m_funds.find(fundType)->second.getAmount());
        notifySubscribers(signal);
    }



}


