#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_SELECTFUND_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_SELECTFUND_HPP

#include <iostream>

#include <frontend/source/viewModel/ui/operations/signal/SelectFund.hpp>
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

class SelectFund :
    public utils::designPattern::SignalPublisher<frontend::viewModel::ui::operations::signal::SelectFund>
{
  public:
    SelectFund();

    void selectFund(model::operations::kFundType fundType);
};

}  // namespace operations
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend

#endif  // FRONTEND_VIEWMODEL_UI_OPERATIONS_SELECTFUND_HPP
