#include "SelectFundViewModel.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

SelectFundViewModel::SelectFundViewModel()
{

}

void SelectFundViewModel::selectFund(model::FundType fundType)
{
    frontend::viewModel::ui::operations::signal::SelectFundSignal signal(fundType);
    notifySubscribers(signal);
}

}
}
}
}
