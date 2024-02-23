#include "SelectFund.hpp"

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

SelectFund::SelectFund(
    std::shared_ptr<frontend::viewModel::ui::operations::SelectFund> selectFundViewModel,
    QQmlApplicationEngine& engine, QObject* parent) :
  mViewModel(selectFundViewModel), mEngine(engine), mParent(parent)
{

}

void SelectFund::setFundType(QString fundType)
{
  try
  {
    model::operations::kFundType modelFundType =
        model::operations::kFundType::_from_string_nocase(fundType.toStdString().c_str());
    mViewModel->selectFund(modelFundType);
  }
  catch (std::runtime_error e)
  {
    e.what();
  }

}

}  // namespace operations
}  // namespace iu
}  // namespace view
}  // namespace frontend
