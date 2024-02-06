#include "TransferViewModel.hpp"


namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

TransferViewModel::TransferViewModel()
{
}

void TransferViewModel::transferMoney(model::FundType destinationFundType, int amount)
{
    frontend::viewModel::signal::TransferedMoneySignal transferedMoneySignal(destinationFundType, amount);
    notifySubscribers(transferedMoneySignal);
}

}
}
}
}
