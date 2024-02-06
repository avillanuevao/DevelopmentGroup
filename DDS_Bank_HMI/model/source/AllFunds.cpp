#include "AllFunds.hpp"

namespace model {

AllFunds::AllFunds(FundType actualFund):
    m_actualFund(actualFund)
{
    //TODO: Eliminar la inicialización a 0
    initFund(model::FundType::SAVINGS);
    initFund(model::FundType::HOUSING);
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

void AllFunds::initFund(model::FundType fundType)
{
    m_funds[fundType] = std::make_shared<model::Fund>(model::Fund(fundType, 0));
}

void AllFunds::notifySubscribersFund(FundType fundType, int amount)
{
    model::signal::UpdatedFundSignal signalUpdatedModel(fundType, amount);
    utils::designPattern::SignalPublisher<model::signal::UpdatedFundSignal>::notifySubscribers(signalUpdatedModel);
}

void AllFunds::notifySubscribersFundType(FundType fundType)
{
    model::signal::UpdatedFundTypeSignal signalUpdatedFundType(fundType);
    utils::designPattern::SignalPublisher<model::signal::UpdatedFundTypeSignal>::notifySubscribers(signalUpdatedFundType);
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

    notifySubscribersFund(m_actualFund, getActualFund()->getAmount());
}

void AllFunds::transferAmount(FundType destinationFundType, int amount)
{
    if(destinationFundType == m_actualFund)
    {
        throw std::logic_error("Fund destination cannot be the same as fund origin");
    }

    int amountFundTypeOrigin = getActualFund()->getAmount();

    if(!(amountFundTypeOrigin >= amount))
    {
        throw std::logic_error("Amount to transfer cant be bigger than the amount in the fund");
    }

    try
    {
        getActualFund()->decreaseAmount(amount);
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

    notifySubscribersFund(m_actualFund, getActualFund()->getAmount());
    notifySubscribersFund(destinationFundType, getFund(destinationFundType)->getAmount());

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

    notifySubscribersFund(m_actualFund, getActualFund()->getAmount());
}


int AllFunds::getAmount() const
{
    return getActualFund()->getAmount();
}

FundType AllFunds::getFundType() const
{
    return m_actualFund;
}


void AllFunds::setAmount(int newAmount)
{
    try
    {
        getActualFund()->setAmount(newAmount);
    }  catch (const std::logic_error& e)
    {
        throw e;
    }
    notifySubscribersFund(m_actualFund, getActualFund()->getAmount());
}

void AllFunds::setAmountByFundType(FundType fundType, int amount)
{
    getFund(fundType)->setAmount(amount);

    notifySubscribersFund(fundType, getFund(fundType)->getAmount());
}

void AllFunds::setFundType(FundType fundType)
{
    m_actualFund = fundType;

    notifySubscribersFundType(m_actualFund);
}

}


