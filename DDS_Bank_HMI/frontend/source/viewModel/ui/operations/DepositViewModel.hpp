#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_DEPOSITVIEWMODEL_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_DEPOSITVIEWMODEL_HPP

#include <memory>

#include <model/source/operations/FundType.hpp>
#include <utils/source/designPattern/SignalPublisher.hpp>
#include <frontend/source/viewModel/ui/operations/signal/DepositMoneySignal.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

class DepositViewModel:
        public utils::designPattern::SignalPublisher<frontend::viewModel::ui::operations::signal::DepositMoneySignal>
{
    public:
        DepositViewModel();
        void depositMoney(int amount);
};

}
}
}
}
#endif // FRONTEND_VIEWMODEL_UI_OPERATIONS_DEPOSITVIEWMODEL_HPP
