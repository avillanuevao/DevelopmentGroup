#include "DepositViewModel.hpp"

viewModel::DepositViewModel::DepositViewModel(model::AllFunds& allFunds) : m_allFunds(allFunds)
{

}

void viewModel::DepositViewModel::depositMoney(int amount, model::FundType fundType)
{
    m_allFunds.increaseAmount(fundType, amount);
}
