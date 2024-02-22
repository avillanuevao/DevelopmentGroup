#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_TRANSFER_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_TRANSFER_HPP

#include <memory>

#include <frontend/source/viewModel/ui/operations/signal/TransferedMoney.hpp>
#include <model/source/operations/kFundType.hpp>
#include <utils/source/designPattern/SignalPublisher.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

class Transfer :
    public utils::designPattern::SignalPublisher<viewModel::ui::operations::signal::TransferedMoney>
{
  public:
    Transfer();

    void transferMoney(model::operations::kFundType destinationFundType, int amount);
};

}  // namespace operations
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend

#endif  // FRONTEND_VIEWMODEL_UI_OPERATIONS_TRANSFER_HPP
