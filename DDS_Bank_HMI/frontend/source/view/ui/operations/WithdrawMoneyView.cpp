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
                                     QQmlApplicationEngine &engine,
                                     QObject *parent):
    m_withdrawViewModel(withdrawViewModel),
    m_engine(engine),
    m_parent(parent)
{
    //TODO: al ser un valor por defecto debería cargarse del caso de uso de inicializar aplicación
    setAmountToWithdraw(0);
}

void WithdrawMoneyView::withdrawMoney()
{
    m_withdrawViewModel->withdrawMoney(m_amountToWithdraw);
}

void WithdrawMoneyView::setAmountToWithdraw(int amount)
{
    m_amountToWithdraw = amount;
}

}
}
}
}
