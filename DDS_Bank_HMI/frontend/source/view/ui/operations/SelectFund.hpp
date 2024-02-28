#ifndef FRONTEND_VIEW_UI_OPERATIONS_SELECTFUND_HPP
#define FRONTEND_VIEW_UI_OPERATIONS_SELECTFUND_HPP

#include <vector>
#include <memory>
#include <iostream>

#include <QObject>
#include <QQmlApplicationEngine>

#include <frontend/source/viewModel/ui/operations/SelectFund.hpp>
#include <model/source/operations/kFundType.hpp>

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

class SelectFund :
    public QObject
{
    Q_OBJECT

  public:
    SelectFund(std::shared_ptr<frontend::viewModel::ui::operations::SelectFund> selectFundViewModel,
               QQmlApplicationEngine& engine, QObject* parent = nullptr);

  public slots:
    void setFundType(int fundType);

  private:
    std::shared_ptr<frontend::viewModel::ui::operations::SelectFund> mViewModel;
    QQmlApplicationEngine& mEngine;
    QObject* mParent;
    std::vector<model::operations::kFundType> mOrderFundType;
};

}  // namespace operations
}  // namespace iu
}  // namespace view
}  // namespace frontend

#endif  // FRONTEND_VIEW_UI_OPERATIONS_SELECTFUND_HPP
