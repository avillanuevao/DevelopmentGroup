#include "Communication.hpp"

namespace frontend
{
namespace viewModel
{
namespace dds
{
namespace operations
{

Communication::Communication(std::shared_ptr<model::operations::iFundSetParameter> fundSetParameter,
                             std::shared_ptr<model::operations::iFundSetAmountByFundType>
                             fundSetAmountByFundType) :
  mFundSetParameter(fundSetParameter), mFundSetAmountByFundType(fundSetAmountByFundType)
{

}

void Communication::updateFundType(model::operations::kFundType fundType)
{
  mFundSetParameter->setFundType(fundType);
}

void Communication::updateAmount(model::operations::kFundType fundType, int amount)
{
  mFundSetAmountByFundType->setAmount(fundType, amount);
}

}  // namespace operations
}  // namespace dds
}  // namespace viewModel
}  // namespace frontend
