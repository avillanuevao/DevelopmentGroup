#include "DepositViewModel.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

DepositViewModel::DepositViewModel(std::shared_ptr<model::AllFunds> allFunds) : m_allFunds(allFunds)
{

}

void DepositViewModel::depositMoney(int amount, FundType fundType)
{
    m_allFunds->increaseAmount(fundType, amount);
    signal::DepositMoneySignal depositMoneySignal(fundType, amount);
    notifySubscribers(depositMoneySignal);
}

}
}
}
}
