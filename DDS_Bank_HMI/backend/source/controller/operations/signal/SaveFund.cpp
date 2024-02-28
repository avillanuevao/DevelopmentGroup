#include "SaveFund.hpp"

namespace backend
{
namespace controller
{
namespace operations
{
namespace signal
{

SaveFund::SaveFund(model::operations::kFundType fundChanged) :
  mFundChanged(fundChanged)
{

}

const model::operations::kFundType& SaveFund::getFundChanged() const
{
  return mFundChanged;
}

}  // namespace signal
}  // namespace operations
}  // namespace controller
}  // namespace backend
