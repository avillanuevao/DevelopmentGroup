#include "DDSViewModel.hpp"

namespace frontend
{
namespace viewModel
{
namespace dds
{
namespace operations
{

DDSViewModel::DDSViewModel(std::shared_ptr<model::operations::iFundSetParameter> fundSetParameter,
                           std::shared_ptr<model::operations::iFundSetAmountByFundType> fundSetAmountByFundType) :
  mFundSetParameter(fundSetParameter), mFundSetAmountByFundType(fundSetAmountByFundType)
{

}

void DDSViewModel::updateFundType(model::operations::kFundType fundType)
{
  mFundSetParameter->setFundType(fundType);
}

void DDSViewModel::updateAmount(model::operations::kFundType fundType, int amount)
{
  mFundSetAmountByFundType->setAmount(fundType, amount);
}

}  // namespace operations
}  // namespace dds
}  // namespace viewModel
}  // namespace frontend
