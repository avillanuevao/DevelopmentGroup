#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_WITHDRAWNMONEY_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_WITHDRAWNMONEY_HPP

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

class WithdrawnMoney
{
  public:
    WithdrawnMoney(int amount);

    int getAmount() const;

  private:
    int mAmount;
};

}  // namespace signal
}  // namespace operations
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend

#endif // FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_WITHDRAWNMONEY_HPP
