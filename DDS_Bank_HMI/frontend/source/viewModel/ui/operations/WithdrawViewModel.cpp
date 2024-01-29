#include "WithdrawViewModel.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

WithdrawViewModel::WithdrawViewModel(std::shared_ptr<model::AllFunds> allFunds):
    m_allFunds(allFunds)
{

}

void WithdrawViewModel::update(model::signal::MoneyWithdrawnSignal signal)
{
    viewModel::signal::MoneyWithdrawnSignal moneyWithdrawnSignal(signal.getFundType(), signal.getAmount());
    utils::designPattern::SignalPublisher<viewModel::signal::MoneyWithdrawnSignal>::notifySubscribers(moneyWithdrawnSignal);
}

void WithdrawViewModel::withdrawMoney(model::FundType fundType, int amount)
{
    viewModel::signal::WithdrawnMoneySignal withdrawnMoneySignal(fundType, amount);
    utils::designPattern::SignalPublisher<viewModel::signal::WithdrawnMoneySignal>::notifySubscribers(withdrawnMoneySignal);
}

}
}
}
}
