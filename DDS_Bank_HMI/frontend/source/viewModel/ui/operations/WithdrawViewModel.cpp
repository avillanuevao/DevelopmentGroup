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

void WithdrawViewModel::withdrawMoney(model::FundType fundType, int amount)
{
    viewModel::signal::WithdrawnMoneySignal withdrawnMoneySignal(fundType, amount);
    notifySubscribers(withdrawnMoneySignal);
}

}
}
}
}
