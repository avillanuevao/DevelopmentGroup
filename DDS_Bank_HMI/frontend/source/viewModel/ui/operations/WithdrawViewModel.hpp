#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_WITHDRAWVIEWMODEL_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_WITHDRAWVIEWMODEL_HPP

#include <utils/source/designPattern/SignalPublisher.hpp>
#include <frontend/source/viewModel/ui/operations/signal/WithdrawnMoneySignal.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

class WithdrawViewModel:
        public utils::designPattern::SignalPublisher<frontend::viewModel::ui::operations::signal::WithdrawnMoneySignal>
{
    public:
        WithdrawViewModel();

        void withdrawMoney(int amount);
};

}
}
}
}
#endif // FRONTEND_VIEWMODEL_UI_OPERATIONS_WITHDRAWVIEWMODEL_HPP
