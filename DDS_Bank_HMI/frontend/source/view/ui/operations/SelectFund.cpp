#include "SelectFund.hpp"

using kFundType = model::operations::kFundType;

namespace frontend
{
namespace view
{
namespace ui
{
namespace operations
{

SelectFund::SelectFund(std::shared_ptr<frontend::viewModel::ui::operations::SelectFund> selectFundViewModel,
                       QQmlApplicationEngine& engine, QObject* parent) :
  mViewModel(selectFundViewModel), mEngine(engine), mParent(parent)
{
  mOrderFundType.push_back(kFundType::Savings);
  mOrderFundType.push_back(kFundType::Housing);
}

void SelectFund::setFundType(int fundType)
{
  try
  {
    mViewModel->selectFund(mOrderFundType.at(fundType));
  }
  catch (std::runtime_error e)
  {
    std::cerr << __FUNCTION__ << e.what() << std::endl;
  }

}

}  // namespace operations
}  // namespace iu
}  // namespace view
}  // namespace frontend
