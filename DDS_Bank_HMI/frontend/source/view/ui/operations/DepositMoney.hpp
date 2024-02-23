#ifndef FRONTEND_VIEW_UI_OPERATIONS_DEPOSITMONEY_HPP
#define FRONTEND_VIEW_UI_OPERATIONS_DEPOSITMONEY_HPP

#include <iostream>

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>

#include <frontend/source/viewModel/ui/operations/Deposit.hpp>
#include <model/source/operations/kFundType.hpp>

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

class DepositMoney :
    public QObject
{
    Q_OBJECT

  public:
    explicit DepositMoney(std::shared_ptr<viewModel::ui::operations::Deposit> depositViewModel,
                              QQmlApplicationEngine& engine, QObject* parent = nullptr);

  public slots:
    void depositMoney();

    void setAmountToDeposit(int amount);

  private:
    std::shared_ptr<viewModel::ui::operations::Deposit> mViewModel;
    QQmlApplicationEngine& mEngine;
    QObject* mParent;
    int mAmountToDeposit;
};

}  // namespace operations
}  // namespace iu
}  // namespace view
}  // namespace frontend

#endif  // FRONTEND_VIEW_UI_OPERATIONS_DEPOSITMONEY_HPP
