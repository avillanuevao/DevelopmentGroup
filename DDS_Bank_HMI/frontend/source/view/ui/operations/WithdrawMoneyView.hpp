#ifndef FRONTEND_VIEW_UI_OPERATIONS_WITHDRAWMONEYVIEW_HPP
#define FRONTEND_VIEW_UI_OPERATIONS_WITHDRAWMONEYVIEW_HPP

#include <iostream>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlComponent>

#include <model/source/FundType.hpp>
#include <model/source/AllFunds.hpp>
#include <frontend/source/viewModel/ui/operations/WithdrawViewModel.hpp>

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

class WithdrawMoneyView:
        public QObject
{
    Q_OBJECT
    public:
        WithdrawMoneyView(std::shared_ptr<viewModel::ui::operations::WithdrawViewModel> withdrawViewModel,
                          std::shared_ptr<model::AllFunds> allFunds,
                          QQmlApplicationEngine &engine,
                          QObject *parent = nullptr);

    public slots:
        void withdrawMoney();
        int getAmountFromFund();
        void setAmountToWithdraw(int amount);
        model::FundType getFundType();
        void setFundType(int fundType);

    private:
        std::shared_ptr<viewModel::ui::operations::WithdrawViewModel> m_withdrawViewModel;
        const std::shared_ptr<model::AllFunds> m_allFunds;
        QQmlApplicationEngine& m_engine;
        QObject* m_parent;
        int m_amountToWithdraw;
        int m_amountFromFund;
        model::FundType m_fundType;
};

}
}
}
}

#endif // FRONTEND_VIEW_UI_OPERATIONS_WITHDRAWMONEYVIEW_HPP
