#include "TransferViewModel.hpp"


namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

TransferViewModel::TransferViewModel(std::shared_ptr<model::AllFunds> allFunds) :
    m_allFunds(allFunds)
{

}

void TransferViewModel::transferMoney(model::FundType originFundType, model::FundType destinationFundType, int amount)
{
    frontend::viewModel::signal::TransferedMoneySignal transferMoneySignal(originFundType, destinationFundType, amount);
    utils::designPattern::SignalPublisher<frontend::viewModel::signal::TransferedMoneySignal>::notifySubscribers(transferMoneySignal);
}

}
}
}
}
