#include "WithdrawMoneyView.hpp"

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

WithdrawMoneyView::WithdrawMoneyView(std::shared_ptr<viewModel::ui::operations::WithdrawViewModel> withdrawViewModel,
                                     std::shared_ptr<model::AllFunds> allFunds,
                                     QQmlApplicationEngine &engine,
                                     QObject *parent):
    m_withdrawViewModel(withdrawViewModel),
    m_allFunds(allFunds),
    m_engine(engine),
    m_parent(parent)
{
    m_amountToWithdraw = 0;
    m_amountFromFund = 0;
}

void WithdrawMoneyView::update(viewModel::signal::MoneyWithdrawnSignal signal)
{
    m_amountFromFund = signal.getAmount();

    QMetaObject::invokeMethod(this, "updateAmountQML",
                              Qt::QueuedConnection, Q_ARG(QVariant, m_amountFromFund));

}

void WithdrawMoneyView::withdrawMoney()
{
    m_withdrawViewModel->withdrawMoney(m_fundType, m_amountToWithdraw);
}

int WithdrawMoneyView::getAmountFromFund()
{
    return m_allFunds->getAmount();
}

void WithdrawMoneyView::setAmountToWithdraw(int amount)
{
    m_amountToWithdraw = amount;
}

model::FundType WithdrawMoneyView::getFundType()
{
    return m_fundType;
}

void WithdrawMoneyView::setFundType(int fundType)
{
    m_fundType = static_cast<model::FundType>(fundType);
}

void WithdrawMoneyView::updateAmountQML(const QVariant &newAmount)
{
    if(!m_engine.rootObjects().isEmpty())
    {
        QObject* rootObject = m_engine.rootObjects().first(); // Obtengo lo que es el objeto Window, la raiz
        QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject); // Aqui tengo el objeto como tipo ventana
        if(rootWindow)
        {
            QObject* textQML = rootObject->findChild<QObject*>("displayTW", Qt::FindChildrenRecursively);
            if(textQML)
            {
                textQML->setProperty("text", newAmount);
            }else
            {
                std::cerr << "Error: Unable to find QML object with id 'displayTW'." << std::endl;
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
}
}
}
