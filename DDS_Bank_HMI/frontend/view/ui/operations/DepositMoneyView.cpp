#include "DepositMoneyView.hpp"

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

DepositMoneyView::DepositMoneyView(std::shared_ptr<viewModel::ui::operations::DepositViewModel> depositViewModel,
                                   const std::shared_ptr<model::AllFunds> allFunds,
                                   QQmlApplicationEngine &engine,
                                   QObject *parent) :
    m_depositViewModel(depositViewModel),
    m_allFunds(allFunds),
    m_engine(engine),
    m_parent(parent)
{
    //TODO: al ser un valor por defecto debería cargarse del caso de uso de inicializar aplicación
    m_amountToDeposit = 0;
    m_amountFromFund = 0;
}

void DepositMoneyView::update(model::signal::MoneyDepositedSignal signal)
{
    std::cout << "Signal recieved." << std::endl;
    m_amountFromFund = signal.getAmount();

    if(!m_engine.rootObjects().isEmpty())
    {
        QObject* rootObject = m_engine.rootObjects().first(); // Obtengo lo que es el objeto Window, la raiz
        QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject); // Aqui tengo el objeto como tipo ventana
        if(rootWindow)
        {
            QObject* textQML = rootObject->findChild<QObject*>("displayT", Qt::FindChildrenRecursively);
            if(textQML)
            {
                textQML->setProperty("text", m_amountFromFund);
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

int DepositMoneyView::getAmountFromFund()
{
    return m_amountFromFund;
}

void DepositMoneyView::setAmountToDeposit(int amount)
{
    m_amountToDeposit = amount;
}

model::FundType DepositMoneyView::getFundType()
{
    return m_fundType;
}

void DepositMoneyView::setFundType(int fundType)
{
    m_fundType = static_cast<model::FundType>(fundType);
}

void DepositMoneyView::depositMoney()
{
    m_depositViewModel->depositMoney(m_fundType, m_amountToDeposit);
}

}
}
}
}

