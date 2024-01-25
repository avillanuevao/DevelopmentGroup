#include "AllFunds.hpp"

namespace model {

AllFunds::AllFunds()
{
    //TODO: Eliminar la inicialización a 0
    m_funds.insert(std::make_pair<model::FundType, Fund>(
                       model::FundType::SAVINGS, model::Fund(model::FundType::SAVINGS, 0)));
    m_funds.insert(std::make_pair<model::FundType, Fund>(
                       model::FundType::HOUSING, model::Fund(model::FundType::HOUSING, 0)));
}

void AllFunds::increaseAmount(model::FundType fundType, int amount)
{
    try
    {
        m_funds.find(fundType)->second.increaseAmount(amount);
    }  catch (const std::logic_error& e)
    {
        throw e;
    }
    model::signal::MoneyDepositedSignal signal =
            model::signal::MoneyDepositedSignal(fundType, m_funds.find(fundType)->second.getAmount());
    utils::designPattern::SignalPublisher<model::signal::MoneyDepositedSignal>::notifySubscribers(signal);
}

void AllFunds::decreaseAmount(FundType fundType, int amount)
{
    try
    {
        m_funds.find(fundType)->second.decreaseAmount(amount);
    }  catch (const std::logic_error& e)
    {
        throw e;
    }
    model::signal::MoneyWithdrawnSignal signal =
            model::signal::MoneyWithdrawnSignal(fundType, m_funds.find(fundType)->second.getAmount());
    utils::designPattern::SignalPublisher<model::signal::MoneyWithdrawnSignal>::notifySubscribers(signal);
}

int AllFunds::getAmount(model::FundType fundType) const
{
    return m_funds.find(fundType)->second.getAmount();
}

void AllFunds::setAmount(model::FundType fundType, int newAmount)
{
    std::cout << "setAmount: [fundType: " << static_cast<int>(fundType)
              << ", amount: " << newAmount << "]" << std::endl;
    try
    {
        m_funds.find(fundType)->second.setAmount(newAmount);
    }  catch (const std::logic_error& e)
    {
        throw e;
    }

    model::signal::MoneyDepositedSignal signalDeposit =
            model::signal::MoneyDepositedSignal(fundType, m_funds.find(fundType)->second.getAmount());
    utils::designPattern::SignalPublisher<model::signal::MoneyDepositedSignal>::notifySubscribers(signalDeposit);

    model::signal::MoneyWithdrawnSignal signalWithdrawn =
            model::signal::MoneyWithdrawnSignal(fundType, m_funds.find(fundType)->second.getAmount());
    utils::designPattern::SignalPublisher<model::signal::MoneyWithdrawnSignal>::notifySubscribers(signalWithdrawn);
}

}


