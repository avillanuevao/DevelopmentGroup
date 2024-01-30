#include "DepositViewModel.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

DepositViewModel::DepositViewModel(std::shared_ptr<model::AllFunds> allFunds)
{

}

void DepositViewModel::depositMoney(model::FundType fundType, int amount)
{
    viewModel::signal::DepositMoneySignal depositMoneySignal(fundType, amount);
    utils::designPattern::SignalPublisher<viewModel::signal::DepositMoneySignal>::notifySubscribers(depositMoneySignal);
}

void DepositViewModel::update(model::signal::MoneyDepositedSignal signal)
{
    viewModel::signal::MoneyDepositedSignal moneyDepositedSignal(signal.getFundType(), signal.getAmount());
    utils::designPattern::SignalPublisher<viewModel::signal::MoneyDepositedSignal>::notifySubscribers(moneyDepositedSignal);
}

}
}
}
}
