#ifndef FRONTEND_VIEW_UI_OPERATIONS_TRANSFERMONEYVIEW_HPP
#define FRONTEND_VIEW_UI_OPERATIONS_TRANSFERMONEYVIEW_HPP

#include <iostream>

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlComponent>

#include <model/source/FundType.hpp>
#include <frontend/source/viewModel/ui/operations/TransferViewModel.hpp>

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

class TransferMoneyView :
        public QObject
{
    Q_OBJECT
    public:
        TransferMoneyView(std::shared_ptr<viewModel::ui::operations::TransferViewModel> transferViewModel,
                          QQmlApplicationEngine &engine,
                          QObject *parent = nullptr);

public slots:
        void transferMoney();

        void setAmountToTransfer(int newAmountToTransfer);
        void setDestinationFundType(int newDestinationFundType);

private:
        std::shared_ptr<viewModel::ui::operations::TransferViewModel> m_transferViewModel;
        QQmlApplicationEngine& m_engine;
        QObject* m_parent;

        int m_amountToTransfer;
        model::FundType m_destinationFundType;

};


}
}
}
}

#endif // FRONTEND_VIEW_UI_OPERATIONS_TRANSFERMONEYVIEW_HPP
