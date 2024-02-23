#include "WithdrawMoney.hpp"

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

WithdrawMoney::WithdrawMoney(
    std::shared_ptr<frontend::viewModel::ui::operations::Withdraw> withdrawViewModel,
    QQmlApplicationEngine& engine, QObject* parent) :
  mViewModel(withdrawViewModel), mEngine(engine), mParent(parent)
{
  //TODO: al ser un valor por defecto debería cargarse del caso de uso de inicializar aplicación
  setAmountToWithdraw(0);
}

void WithdrawMoney::withdrawMoney()
{
  mViewModel->withdrawMoney(mAmountToWithdraw);
}

void WithdrawMoney::setAmountToWithdraw(int amount)
{
  mAmountToWithdraw = amount;
}

}  // namespace operations
}  // namespace iu
}  // namespace view
}  // namespace frontend
