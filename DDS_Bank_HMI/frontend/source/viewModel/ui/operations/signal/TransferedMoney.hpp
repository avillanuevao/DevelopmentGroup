#ifndef FRONTEND_VIEWMODEL_SIGNAL_TRANSFEREDMONEY_HPP
#define FRONTEND_VIEWMODEL_SIGNAL_TRANSFEREDMONEY_HPP

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

class TransferedMoney
{
  public:
    TransferedMoney(model::operations::kFundType destinationFundType, int amount);

    model::operations::kFundType getDestinationFundType() const;
    int getAmount() const;

  private:
    model::operations::kFundType mDestinationFundType;
    int mAmount;
};

}  // namespace signal
}  // namespace operations
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend

#endif  // FRONTEND_VIEWMODEL_SIGNAL_TRANSFEREDMONEY_HPP
