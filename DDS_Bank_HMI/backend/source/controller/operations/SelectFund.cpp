#include "SelectFund.hpp"

namespace backend
{
namespace controller
{
namespace operations
{

SelectFund::SelectFund(std::shared_ptr<model::operations::iFundSetParameter> fund) :
  mFund(fund)
{

}

void SelectFund::selectFundType(model::operations::kFundType fundType)
{
  mFund->setFundType(fundType);
}

}  // namespace operations
}  // namespace controller
}  // namespace backend
