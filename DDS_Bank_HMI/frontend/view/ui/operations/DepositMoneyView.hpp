#ifndef DEPOSITMONEYVIEW_HPP
#define DEPOSITMONEYVIEW_HPP

#include <iostream>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlComponent>

#include <idl/bank.hpp>
#include <utils/designPattern/SignalSubscriber.hpp>
#include <model/AllFunds.hpp>
#include <model/signal/MoneyDepositedSignal.hpp>
#include <frontend/viewModel/ui/operations/DepositViewModel.hpp>

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

class DepositMoneyView : public QObject,
        public utils::designPattern::SignalSubscriber<model::signal::MoneyDepositedSignal>
{
    Q_OBJECT
    public:
        explicit DepositMoneyView(viewModel::ui::operations::DepositViewModel& depositViewModel,
                                  const model::AllFunds& allFunds,
                                  QQmlApplicationEngine &engine,
                                  QObject *parent = nullptr);

        void update(model::signal::MoneyDepositedSignal signal);

    public slots:
        int getAmountFromFund();
        void setAmountToDeposit(int amount);
        FundType getFundType();
        void setFundType(int fundType);
        void depositMoney();

    private:
        viewModel::ui::operations::DepositViewModel& m_depositViewModel;
        const model::AllFunds& m_allFunds;
        QQmlApplicationEngine& m_engine;
        QObject* m_parent;
        int m_amountToDeposit;
        int m_amountFromFund;
        FundType m_fundType; //TODO: Cual sería el valor inicial que le queremos dar?
};

}
}
}
}


#endif // DEPOSITMONEYVIEW_HPP
