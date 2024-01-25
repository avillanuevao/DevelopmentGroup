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

void WithdrawMoneyView::withdrawMoney()
{
    m_withdrawViewModel->withdrawMoney(m_fundType, m_amountToWithdraw);
}

int WithdrawMoneyView::getAmountFromFund()
{
    return m_allFunds->getAmount(m_fundType);
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

}
}
}
}
