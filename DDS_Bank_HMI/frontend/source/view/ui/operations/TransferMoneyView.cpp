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

void TransferMoneyView::update(viewModel::signal::MoneyTransferedSignal signal)
{
    if(m_originFundType == signal.getFundType())
    {

        m_amountFromOriginFund = signal.getAmount();

        if(!m_engine.rootObjects().isEmpty())
        {
            QObject* rootObject = m_engine.rootObjects().first(); // Obtengo lo que es el objeto Window, la raiz
            QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject); // Aqui tengo el objeto como tipo ventana
            if(rootWindow)
            {
                QObject* textQML = rootObject->findChild<QObject*>("displayTransferText", Qt::FindChildrenRecursively);
                if(textQML)
                {
                    textQML->setProperty("text", m_amountFromOriginFund);
                }else
                {
                    std::cerr << "Error: Unable to find QML object with id 'displayT'." << std::endl;
                }
            }else
            {
                std::cerr << "Error: Root object is not a QQuickWindow." << std::endl;
            }

        }else
        {
            std::cerr << "Error: No root objects found." << std::endl;
        }
    }

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


