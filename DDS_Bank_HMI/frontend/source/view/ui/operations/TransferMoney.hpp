#ifndef FRONTEND_VIEW_UI_OPERATIONS_TRANSFERMONEY_HPP
#define FRONTEND_VIEW_UI_OPERATIONS_TRANSFERMONEY_HPP

#include <iostream>

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickWindow>

#include <frontend/source/viewModel/ui/operations/Transfer.hpp>
#include <model/source/operations/kFundType.hpp>

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

class TransferMoney :
    public QObject
{
    Q_OBJECT
  public:
    TransferMoney(std::shared_ptr<frontend::viewModel::ui::operations::Transfer> transferViewModel,
                  QQmlApplicationEngine& engine, QObject* parent = nullptr);

  public slots:
    void transferMoney();

    void setAmountToTransfer(int newAmountToTransfer);
    void setDestinationFundType(QString newDestinationFundType);

  private:
    std::shared_ptr<frontend::viewModel::ui::operations::Transfer> mViewModel;
    QQmlApplicationEngine& mEngine;
    QObject* mParent;
    int mAmountToTransfer;
    model::operations::kFundType mDestinationFundType;
};

}  // namespace operations
}  // namespace iu
}  // namespace view
}  // namespace frontend

#endif  // FRONTEND_VIEW_UI_OPERATIONS_TRANSFERMONEY_HPP
