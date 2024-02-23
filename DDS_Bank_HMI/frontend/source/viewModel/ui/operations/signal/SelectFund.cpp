#include "SelectFund.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{
namespace signal
{

SelectFund::SelectFund(model::operations::kFundType fundType) :
  mFundType(fundType)
{

}

model::operations::kFundType SelectFund::getFundType() const
{
  return mFundType;
}

void SelectFund::setFundType(model::operations::kFundType newFundType)
{
  mFundType = newFundType;
}

}  // namespace signal
}  // namespace operations
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend
