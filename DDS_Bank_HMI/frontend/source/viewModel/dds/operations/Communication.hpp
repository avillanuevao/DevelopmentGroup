#ifndef FRONTEND_VIEWMODEL_DDS_OPERATIONS_COMMUNICATION_HPP
#define FRONTEND_VIEWMODEL_DDS_OPERATIONS_COMMUNICATION_HPP

#include <memory>

#include <model/source/operations/iFundSetAmountByFundType.hpp>
#include <model/source/operations/iFundSetParameter.hpp>

namespace frontend
{
namespace viewModel
{
namespace dds
{
namespace operations
{

class Communication
{
  public:
    Communication(std::shared_ptr<model::operations::iFundSetParameter> fundSetParameter,
                  std::shared_ptr<model::operations::iFundSetAmountByFundType> fundSetAmountByFundType);

    void updateFundType(model::operations::kFundType fundType);
    void updateAmount(model::operations::kFundType fundType, int amount);

  private:
    std::shared_ptr<model::operations::iFundSetParameter> mFundSetParameter;
    std::shared_ptr<model::operations::iFundSetAmountByFundType> mFundSetAmountByFundType;
};

}  // namespace operations
}  // namespace dds
}  // namespace viewModel
}  // namespace frontend

#endif  // FRONTEND_VIEWMODEL_DDS_OPERATIONS_COMMUNICATION_HPP
