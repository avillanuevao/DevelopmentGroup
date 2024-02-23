#include "TransferMoney.hpp"

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

TransferMoney::TransferMoney(std::shared_ptr<frontend::viewModel::ui::operations::Transfer> transferViewModel,
                             QQmlApplicationEngine& engine, QObject* parent) :
  mViewModel(transferViewModel), mEngine(engine), mParent(parent),
  mDestinationFundType(model::operations::kFundType::Savings)
{
  // TODO: al ser un valor por defecto debería cargarse del caso de uso de inicializar aplicación
  mAmountToTransfer = 0;
}

void TransferMoney::transferMoney()
{
  mViewModel->transferMoney(mDestinationFundType, mAmountToTransfer);
}

void TransferMoney::setAmountToTransfer(int newAmountToTransfer)
{
  mAmountToTransfer = newAmountToTransfer;
}

void TransferMoney::setDestinationFundType(QString newDestinationFundType)
{
  try
  {
    model::operations::kFundType modelFundType =
        model::operations::kFundType::_from_string_nocase(newDestinationFundType.toStdString().c_str());
    mDestinationFundType = modelFundType;
  }
  catch (std::runtime_error e)
  {
    e.what();
  }
}

}  // namespace operations
}  // namespace iu
}  // namespace view
}  // namespace frontend


