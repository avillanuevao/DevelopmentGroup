#include "AllFunds.hpp"

namespace model {

AllFunds::AllFunds(FundType actualFund):
    m_actualFund(actualFund)
{
    //TODO: Eliminar la inicialización a 0
    // TODO: hacerlo en una funcion aparte que sea createNewFund(model::FundType fundType)
    m_funds.insert(std::make_pair<model::FundType, std::shared_ptr<model::Fund>>(
                       model::FundType::SAVINGS, std::make_shared<model::Fund>(model::Fund(model::FundType::SAVINGS, 0))));
    m_funds.insert(std::make_pair<model::FundType, std::shared_ptr<model::Fund>>(
                       model::FundType::SAVINGS, std::make_shared<model::Fund>(model::Fund(model::FundType::HOUSING, 0))));
}

std::shared_ptr<model::FundInterface> model::AllFunds::getFund(model::FundType fundType)
{
    return m_funds.find(fundType)->second;
}

std::shared_ptr<FundInterface> AllFunds::getActualFund()
{
    return getFund(m_actualFund);
}

std::shared_ptr<model::FundInterface> model::AllFunds::getFund(model::FundType fundType) const
{
    return m_funds.find(fundType)->second;
}

std::shared_ptr<FundInterface> AllFunds::getActualFund() const
{
    return getFund(m_actualFund);
}

void AllFunds::increaseAmount(int amount)
{
    try
    {
        getActualFund()->increaseAmount(amount);
    }  catch (const std::logic_error& e)
    {
        throw e;
    }
    model::signal::MoneyDepositedSignal signal =
            model::signal::MoneyDepositedSignal(m_actualFund, m_funds.find(m_actualFund)->second->getAmount());
    utils::designPattern::SignalPublisher<model::signal::MoneyDepositedSignal>::notifySubscribers(signal);
}

void AllFunds::transferAmount(FundType originFundType, FundType destinationFundType, int amount)
{
    int originFundTypeInitAmount = getFund(originFundType)->getAmount();

    if(!(originFundTypeInitAmount >= amount))
    {
        throw std::logic_error("Amount to transfer cant be bigger than the amount in the fund");
    }
    try
    {
        getFund(originFundType)->decreaseAmount(amount);
    }  catch (const std::logic_error& e)
    {
        throw e;
    }

    try
    {
        getFund(destinationFundType)->increaseAmount(amount);
    }  catch (const std::logic_error& e)
    {
        throw e;
    }

    model::signal::MoneyTransferedSignal signalOriginData =
            model::signal::MoneyTransferedSignal(originFundType,
                                                 getFund(originFundType)->getAmount());
    model::signal::MoneyTransferedSignal signalDestinationData =
            model::signal::MoneyTransferedSignal(destinationFundType,
                                                 getFund(destinationFundType)->getAmount());

    utils::designPattern::SignalPublisher<model::signal::MoneyTransferedSignal>::notifySubscribers(signalOriginData);
    utils::designPattern::SignalPublisher<model::signal::MoneyTransferedSignal>::notifySubscribers(signalDestinationData);

}

void AllFunds::decreaseAmount(int amount)
{
    try
    {
        getActualFund()->decreaseAmount(amount);
    }  catch (const std::logic_error& e)
    {
        throw e;
    }
    model::signal::MoneyWithdrawnSignal signal =
            model::signal::MoneyWithdrawnSignal(m_actualFund, getActualFund()->getAmount());
    utils::designPattern::SignalPublisher<model::signal::MoneyWithdrawnSignal>::notifySubscribers(signal);
}

int AllFunds::getAmount() const
{
    return getActualFund()->getAmount();
}

void AllFunds::setAmount(model::FundType fundType, int newAmount)
{
    std::cout << "setAmount: " << std::endl
              << "\t[fundType: " << static_cast<int>(fundType) << ", amount: " << newAmount << "]" << std::endl;
    try
    {
        getActualFund()->setAmount(newAmount);
    }  catch (const std::logic_error& e)
    {
        throw e;
    }

    // TODO: esto es la misma señal, habría que eliminar el resto
    model::signal::MoneyDepositedSignal signalDeposit =
            model::signal::MoneyDepositedSignal(fundType, getActualFund()->getAmount());
    utils::designPattern::SignalPublisher<model::signal::MoneyDepositedSignal>::notifySubscribers(signalDeposit);
    model::signal::MoneyWithdrawnSignal signalWithdrawn =
            model::signal::MoneyWithdrawnSignal(fundType, getActualFund()->getAmount());
    utils::designPattern::SignalPublisher<model::signal::MoneyWithdrawnSignal>::notifySubscribers(signalWithdrawn);
    model::signal::MoneyTransferedSignal signalTransfer =
            model::signal::MoneyTransferedSignal(fundType, getActualFund()->getAmount());
    utils::designPattern::SignalPublisher<model::signal::MoneyTransferedSignal>::notifySubscribers(signalTransfer);
}

void AllFunds::setAmount(int newAmount)
{
    setAmount(m_actualFund, newAmount);
}

void AllFunds::setActualFund(model::FundType newActualFund)
{
    m_actualFund = newActualFund;
}

}


