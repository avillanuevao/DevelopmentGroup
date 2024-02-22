#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_SELECTFUND_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_SELECTFUND_HPP

#include <model/source/operations/kFundType.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{
namespace signal
{

class SelectFund
{
  public:
    SelectFund(model::operations::kFundType fundType);

    model::operations::kFundType getFundType() const;
    void setFundType(model::operations::kFundType newFundType);

  private:
    model::operations::kFundType mFundType;
};

}  // namespace signal
}  // namespace operations
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend

#endif  // FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_SELECTFUND_HPP
