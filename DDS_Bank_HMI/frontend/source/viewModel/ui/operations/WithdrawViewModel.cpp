#include "WithdrawViewModel.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

WithdrawViewModel::WithdrawViewModel()
{

}

void WithdrawViewModel::withdrawMoney(int amount)
{
    frontend::viewModel::ui::operations::signal::WithdrawnMoneySignal withdrawnMoneySignal(amount);
    notifySubscribers(withdrawnMoneySignal);
}

}
}
}
}
