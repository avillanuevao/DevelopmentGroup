#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_WITHDRAW_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_WITHDRAW_HPP

#include <frontend/source/viewModel/ui/operations/signal/WithdrawnMoney.hpp>
#include <utils/source/designPattern/SignalPublisher.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

class Withdraw:
    public utils::designPattern::SignalPublisher<viewModel::ui::operations::signal::WithdrawnMoney>
{
  public:
    Withdraw();

    void withdrawMoney(int amount);
};

}  // namespace operations
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend

#endif  // FRONTEND_VIEWMODEL_UI_OPERATIONS_WITHDRAW_HPP
