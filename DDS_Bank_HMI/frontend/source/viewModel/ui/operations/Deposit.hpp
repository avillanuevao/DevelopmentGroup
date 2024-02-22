#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_DEPOSIT_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_DEPOSIT_HPP

#include <memory>

#include <frontend/source/viewModel/ui/operations/signal/DepositMoney.hpp>
#include <utils/source/designPattern/SignalPublisher.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

class Deposit:
    public utils::designPattern::SignalPublisher<frontend::viewModel::ui::operations::signal::DepositMoney>
{
  public:
    Deposit();

    void depositMoney(int amount);
};

}  // namespace operations
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend

#endif  // FRONTEND_VIEWMODEL_UI_OPERATIONS_DEPOSITL_HPP
