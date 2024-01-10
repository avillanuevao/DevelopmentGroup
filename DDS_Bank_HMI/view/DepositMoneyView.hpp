#ifndef DEPOSITMONEYVIEW_HPP
#define DEPOSITMONEYVIEW_HPP

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlComponent>
#include <iostream>
#include <model/FundType.hpp>
#include <viewModel/DepositViewModel.hpp>
#include <model/AllFunds.hpp>
#include <model/signal/MoneyDepositedSignal.hpp>
#include <utils/SignalSubscriber.hpp>

namespace view
{
    class DepositMoneyView : public QObject, public utils::SignalSubscriber<model::MoneyDepositedSignal>
    {
        Q_OBJECT
        public:
            explicit DepositMoneyView(viewModel::DepositViewModel& depositViewModel, const model::AllFunds& allFunds, QQmlApplicationEngine &engine, QObject *parent = nullptr);

            void update(model::MoneyDepositedSignal signal);

        public slots:
            int getAmountFromFund();
            void setAmountToDeposit(int amount);
            model::FundType getFundType();
            void setFundType(int fundType);
            void depositMoney();


        private:
            QQmlApplicationEngine& m_engine;
            viewModel::DepositViewModel& m_depositViewModel;
            const model::AllFunds& m_allFunds;

            int m_amountToDeposit = 0;
            int m_amountFromFund = 0;
            model::FundType m_fundType;
    };
}



#endif // DEPOSITMONEYVIEW_HPP
