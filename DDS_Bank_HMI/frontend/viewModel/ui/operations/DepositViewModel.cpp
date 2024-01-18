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

void DepositViewModel::depositMoney(model::FundType fundType, int amount)
{
    signal::DepositMoneySignal depositMoneySignal(fundType, amount);
    notifySubscribers(depositMoneySignal);
}

}
}
}
}
