#include "DepositMoney.hpp"

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

DepositMoney::DepositMoney(std::shared_ptr<viewModel::ui::operations::Deposit> depositViewModel,
                           QQmlApplicationEngine& engine, QObject* parent) :
  mViewModel(depositViewModel), mEngine(engine), mParent(parent)
{
  //TODO: al ser un valor por defecto debería cargarse del caso de uso de inicializar aplicación
  setAmountToDeposit(0);
}

void DepositMoney::depositMoney()
{
  mViewModel->depositMoney(mAmountToDeposit);
}

void DepositMoney::setAmountToDeposit(int amount)
{
  mAmountToDeposit = amount;
}

}  // namespace operations
}  // namespace iu
}  // namespace view
}  // namespace frontend
