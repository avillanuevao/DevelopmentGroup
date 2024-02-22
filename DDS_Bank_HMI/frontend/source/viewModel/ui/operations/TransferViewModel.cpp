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

void TransferViewModel::transferMoney(model::operations::kFundType destinationFundType, int amount)
{
    frontend::viewModel::ui::operations::signal::TransferedMoneySignal transferedMoneySignal(destinationFundType, amount);
    notifySubscribers(transferedMoneySignal);
}

}
}
}
}
