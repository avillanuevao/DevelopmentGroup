#include "TransferMoneyView.hpp"


namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

TransferMoneyView::TransferMoneyView(std::shared_ptr<viewModel::ui::operations::TransferViewModel> transferViewModel, const std::shared_ptr<model::AllFunds> allFunds, QQmlApplicationEngine &engine, QObject *parent) :
    m_transferViewModel(transferViewModel),
    m_allFunds(allFunds),
    m_engine(engine),
    m_parent(parent)
{
    //TODO: al ser un valor por defecto debería cargarse del caso de uso de inicializar aplicación
    m_amountFromOriginFund = 0;
    m_amountToTransfer = 0;
}

void TransferMoneyView::transferMoney()
{
    m_transferViewModel->transferMoney(m_originFundType, m_destinationFundType, m_amountToTransfer);
}

int TransferMoneyView::getAmountToTransfer() const
{
    return m_amountToTransfer;
}

void TransferMoneyView::setAmountToTransfer(int newAmountToTransfer)
{
    m_amountToTransfer = newAmountToTransfer;
}

int TransferMoneyView::getAmountFromOriginFund() const
{
    return m_amountFromOriginFund;
}

void TransferMoneyView::setAmountFromOriginFund(int newAmountFromOriginFund)
{
    m_amountFromOriginFund = newAmountFromOriginFund;
}

model::FundType TransferMoneyView::getOriginFundType() const
{
    return m_originFundType;
}

void TransferMoneyView::setOriginFundType(int newOriginFundType)
{
    m_originFundType = static_cast<model::FundType>(newOriginFundType);
}

model::FundType TransferMoneyView::getDestinationFundType() const
{
    return m_destinationFundType;
}

void TransferMoneyView::setDestinationFundType(int newDestinationFundType)
{
    m_destinationFundType = static_cast<model::FundType>(newDestinationFundType);
}

}
}
}
}


