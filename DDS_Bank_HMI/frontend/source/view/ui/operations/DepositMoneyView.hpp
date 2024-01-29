#ifndef DEPOSITMONEYVIEW_HPP
#define DEPOSITMONEYVIEW_HPP

#include <iostream>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQuickItem>
#include <QQmlComponent>

#include <utils/source/designPattern/SignalSubscriber.hpp>
#include <model/source/AllFunds.hpp>
#include <model/source/FundType.hpp>
#include <model/source/signal/MoneyDepositedSignal.hpp>
#include <frontend/source/viewModel/ui/operations/DepositViewModel.hpp>
#include <frontend/source/viewModel/signal/MoneyDepositedSignal.hpp>

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

class DepositMoneyView :
        public QObject,
        public utils::designPattern::SignalSubscriber<frontend::viewModel::signal::MoneyDepositedSignal>
{
    Q_OBJECT
    public:
        explicit DepositMoneyView(std::shared_ptr<viewModel::ui::operations::DepositViewModel> depositViewModel,
                                  const std::shared_ptr<model::AllFunds> allFunds,
                                  QQmlApplicationEngine &engine,
                                  QObject *parent = nullptr);

        void update(frontend::viewModel::signal::MoneyDepositedSignal signal);

    public slots:
        int getAmountFromFund();
        void setAmountToDeposit(int amount);
        model::FundType getFundType();
        void setFundType(int fundType);
        void depositMoney();

    private slots:
        void updateAmountQML(const QVariant& newAmount);

    private:
        std::shared_ptr<viewModel::ui::operations::DepositViewModel> m_depositViewModel;
        const std::shared_ptr<model::AllFunds> m_allFunds;
        QQmlApplicationEngine& m_engine;
        QObject* m_parent;
        int m_amountToDeposit;
        int m_amountFromFund;
        model::FundType m_fundType; //TODO: Cual sería el valor inicial que le queremos dar?
};

}
}
}
}


#endif // DEPOSITMONEYVIEW_HPP
