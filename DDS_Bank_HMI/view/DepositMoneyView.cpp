#include "DepositMoneyView.hpp"

view::DepositMoneyView::DepositMoneyView(viewModel::DepositViewModel &depositViewModel, const model::AllFunds &allFunds, QQmlApplicationEngine &engine, QObject *parent) :
    m_depositViewModel(depositViewModel), m_allFunds(allFunds), m_engine(engine), QObject(parent)
{
}

void view::DepositMoneyView::update(model::MoneyDepositedSignal signal)
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

int view::DepositMoneyView::getAmountFromFund()
{
    return m_amountFromFund;
}

void view::DepositMoneyView::setAmountToDeposit(int amount)
{
    m_amountToDeposit = amount;
}

model::FundType view::DepositMoneyView::getFundType()
{
    return m_fundType;
}

void view::DepositMoneyView::setFundType(int fundType)
{
    m_fundType = static_cast<model::FundType>(fundType);
}

void view::DepositMoneyView::depositMoney()
{
    m_depositViewModel.depositMoney(m_amountToDeposit, m_fundType);
}

