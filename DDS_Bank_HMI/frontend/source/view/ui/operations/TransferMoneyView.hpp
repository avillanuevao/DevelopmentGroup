#ifndef FRONTEND_VIEW_UI_OPERATIONS_TRANSFERMONEYVIEW_HPP
#define FRONTEND_VIEW_UI_OPERATIONS_TRANSFERMONEYVIEW_HPP

#include <iostream>

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlComponent>

#include <model/source/AllFunds.hpp>
#include <model/source/FundType.hpp>
#include <frontend/source/viewModel/ui/operations/TransferViewModel.hpp>
#include <frontend/source/viewModel/signal/MoneyTransferedSignal.hpp>

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

class TransferMoneyView :
        public QObject,
        public utils::designPattern::SignalSubscriber<frontend::viewModel::signal::MoneyTransferedSignal>
{
    Q_OBJECT
    public:
        TransferMoneyView() = default;
        explicit TransferMoneyView(std::shared_ptr<viewModel::ui::operations::TransferViewModel> transferViewModel,
                                   const std::shared_ptr<model::AllFunds> allFunds,
                                   QQmlApplicationEngine &engine,
                                   QObject *parent = nullptr);

        void update(frontend::viewModel::signal::MoneyTransferedSignal signal);

public slots:
        void transferMoney();

        int getAmountToTransfer() const;
        void setAmountToTransfer(int newAmountToTransfer);

        int getAmountFromOriginFund() const;
        void setAmountFromOriginFund(int newAmountFromOriginFund);

        model::FundType getOriginFundType() const;
        void setOriginFundType(int newOriginFundType);

        model::FundType getDestinationFundType() const;
        void setDestinationFundType(int newDestinationFundType);

private:
        std::shared_ptr<viewModel::ui::operations::TransferViewModel> m_transferViewModel;
        const std::shared_ptr<model::AllFunds> m_allFunds;

        QQmlApplicationEngine& m_engine;
        QObject* m_parent;

        int m_amountToTransfer;
        int m_amountFromOriginFund;
        model::FundType m_originFundType;
        model::FundType m_destinationFundType;

};


}
}
}
}

#endif // FRONTEND_VIEW_UI_OPERATIONS_TRANSFERMONEYVIEW_HPP
