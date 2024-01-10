#include "DepositViewModel.hpp"

viewModel::DepositViewModel::DepositViewModel(model::AllFunds& allFunds) : m_allFunds(allFunds)
{

}

void viewModel::DepositViewModel::depositMoney(int amount, FundType fundType)
{
    m_allFunds.increaseAmount(fundType, amount);
    signal::DepositMoneySignal depositMoneySignal(fundType, amount);
    notifySubscribers(depositMoneySignal);
}
