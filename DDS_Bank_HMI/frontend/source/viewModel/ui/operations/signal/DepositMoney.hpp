#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_DEPOSITMONEY_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_DEPOSITMONEY_HPP

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

class DepositMoney
{
  public:
    DepositMoney(int amount);

    int getAmount() const;

  private:
    int mAmount;

};

}  // namespace signal
}  // namespace operations
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend

#endif  // FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_DEPOSITMONEY_HPP
