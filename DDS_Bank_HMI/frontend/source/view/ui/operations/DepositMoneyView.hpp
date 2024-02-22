#ifndef FRONTEND_VIEW_UI_OPERATIONS_DEPOSITMONEYVIEW_HPP
#define FRONTEND_VIEW_UI_OPERATIONS_DEPOSITMONEYVIEW_HPP

#include <iostream>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQuickItem>
#include <QQmlComponent>

#include <model/source/operations/kFundType.hpp>
#include <frontend/source/viewModel/ui/operations/Deposit.hpp>

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

class DepositMoneyView :
        public QObject
{
    Q_OBJECT
    public:
        explicit DepositMoneyView(std::shared_ptr<viewModel::ui::operations::Deposit> depositViewModel,
                                  QQmlApplicationEngine &engine,
                                  QObject *parent = nullptr);

    public slots:
        void setAmountToDeposit(int amount);
        void depositMoney();

    private:
        std::shared_ptr<viewModel::ui::operations::Deposit> m_depositViewModel;
        QQmlApplicationEngine& m_engine;
        QObject* m_parent;
        int m_amountToDeposit;
};

}
}
}
}


#endif // FRONTEND_VIEW_UI_OPERATIONS_DEPOSITMONEYVIEW_HPP
