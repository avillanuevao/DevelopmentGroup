#include "TransferMoneyView.hpp"


namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

TransferMoneyView::TransferMoneyView(std::shared_ptr<frontend::viewModel::ui::operations::TransferViewModel> transferViewModel,
                                     QQmlApplicationEngine &engine,
                                     QObject *parent) :
    m_transferViewModel(transferViewModel),
    m_engine(engine),
    m_parent(parent),
    m_destinationFundType(model::operations::FundType::SAVINGS)
{
    //TODO: al ser un valor por defecto debería cargarse del caso de uso de inicializar aplicación
    m_amountToTransfer = 0;
}

void TransferMoneyView::transferMoney()
{
    m_transferViewModel->transferMoney(m_destinationFundType, m_amountToTransfer);
}

void TransferMoneyView::setAmountToTransfer(int newAmountToTransfer)
{
    m_amountToTransfer = newAmountToTransfer;
}

void TransferMoneyView::setDestinationFundType(QString newDestinationFundType)
{
    try
    {
        m_destinationFundType = model::operations::FundType::_from_string_nocase(newDestinationFundType.toStdString().c_str());
    }
    catch (std::runtime_error e)
    {
        e.what();
    }
}

}
}
}
}


