#include "UpdatedFundType.hpp"

namespace model
{
namespace operations
{
namespace signal
{

UpdatedFundType::UpdatedFundType(model::operations::kFundType fundType):
  mFundType(fundType)
{

}

model::operations::kFundType UpdatedFundType::getFundType() const
{
  return mFundType;
}

void UpdatedFundType::setFundType(model::operations::kFundType newFundType)
{
  mFundType = newFundType;
}

}  // namespace signal
}  // namespace operations
}  // namespace model
