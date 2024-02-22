#ifndef FRONTEND_VIEW_UI_OPERATIONS_WITHDRAWMONEYVIEW_HPP
#define FRONTEND_VIEW_UI_OPERATIONS_WITHDRAWMONEYVIEW_HPP

#include <iostream>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlComponent>

#include <model/source/operations/kFundType.hpp>
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
        WithdrawMoneyView(std::shared_ptr<frontend::viewModel::ui::operations::WithdrawViewModel> withdrawViewModel,
                          QQmlApplicationEngine &engine,
                          QObject *parent = nullptr);

    public slots:
        void withdrawMoney();
        void setAmountToWithdraw(int amount);

    private:
        std::shared_ptr<frontend::viewModel::ui::operations::WithdrawViewModel> m_withdrawViewModel;
        QQmlApplicationEngine& m_engine;
        QObject* m_parent;
        int m_amountToWithdraw;
};

}
}
}
}

#endif // FRONTEND_VIEW_UI_OPERATIONS_WITHDRAWMONEYVIEW_HPP
