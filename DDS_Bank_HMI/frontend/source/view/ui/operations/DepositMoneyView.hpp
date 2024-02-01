#ifndef DEPOSITMONEYVIEW_HPP
#define DEPOSITMONEYVIEW_HPP

#include <iostream>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQuickItem>
#include <QQmlComponent>

#include <model/source/FundType.hpp>
#include <frontend/source/viewModel/ui/operations/DepositViewModel.hpp>

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
        explicit DepositMoneyView(std::shared_ptr<viewModel::ui::operations::DepositViewModel> depositViewModel,
                                  QQmlApplicationEngine &engine,
                                  QObject *parent = nullptr);

    public slots:
        void setAmountToDeposit(int amount);
        void depositMoney();

    private:
        std::shared_ptr<viewModel::ui::operations::DepositViewModel> m_depositViewModel;
        QQmlApplicationEngine& m_engine;
        QObject* m_parent;
        int m_amountToDeposit;
};

}
}
}
}


#endif // DEPOSITMONEYVIEW_HPP
