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
                                   QQmlApplicationEngine &engine,
                                   QObject *parent) :
    m_depositViewModel(depositViewModel),
    m_engine(engine),
    m_parent(parent)
{
    //TODO: al ser un valor por defecto debería cargarse del caso de uso de inicializar aplicación
    setAmountToDeposit(0);
}

void DepositMoneyView::setAmountToDeposit(int amount)
{
    m_amountToDeposit = amount;
}

void DepositMoneyView::depositMoney()
{
    m_depositViewModel->depositMoney(m_amountToDeposit);
}

}
}
}
}

