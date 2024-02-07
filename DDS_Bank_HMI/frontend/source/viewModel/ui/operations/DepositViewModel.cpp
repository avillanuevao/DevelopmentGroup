#include "DepositViewModel.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

DepositViewModel::DepositViewModel()
{

}

void DepositViewModel::depositMoney(int amount)
{
    frontend::viewModel::ui::operations::signal::DepositMoneySignal depositMoneySignal(amount);
    notifySubscribers(depositMoneySignal);
}


}
}
}
}
