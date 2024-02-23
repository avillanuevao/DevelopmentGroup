#ifndef FRONTEND_VIEW_UI_OPERATIONS_WITHDRAWMONEY_HPP
#define FRONTEND_VIEW_UI_OPERATIONS_WITHDRAWMONEY_HPP

#include <iostream>

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickWindow>

#include <frontend/source/viewModel/ui/operations/Withdraw.hpp>
#include <model/source/operations/kFundType.hpp>

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

class WithdrawMoney :
    public QObject
{
    Q_OBJECT
  public:
    WithdrawMoney(std::shared_ptr<frontend::viewModel::ui::operations::Withdraw> withdrawViewModel,
                  QQmlApplicationEngine& engine, QObject* parent = nullptr);

  public slots:
    void withdrawMoney();

    void setAmountToWithdraw(int amount);

  private:
    std::shared_ptr<frontend::viewModel::ui::operations::Withdraw> mViewModel;
    QQmlApplicationEngine& mEngine;
    QObject* mParent;
    int mAmountToWithdraw;
};

}  // namespace operations
}  // namespace iu
}  // namespace view
}  // namespace frontend

#endif  // FRONTEND_VIEW_UI_OPERATIONS_WITHDRAWMONEY_HPP
