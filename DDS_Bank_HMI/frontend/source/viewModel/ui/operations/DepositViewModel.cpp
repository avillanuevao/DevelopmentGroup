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
    viewModel::signal::DepositMoneySignal depositMoneySignal(amount);
    notifySubscribers(depositMoneySignal);
}


}
}
}
}
