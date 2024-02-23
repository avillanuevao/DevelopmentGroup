#ifndef BACKEND_CONTROLLER_OPERATIONS_SELECTFUND_HPP
#define BACKEND_CONTROLLER_OPERATIONS_SELECTFUND_HPP

#include <memory>

#include <model/source/operations/iFundSetParameter.hpp>
#include <model/source/operations/kFundType.hpp>

namespace backend
{
namespace controller
{
namespace operations
{

class SelectFund
{
  public:
    SelectFund(std::shared_ptr<model::operations::iFundSetParameter> fund);

    void selectFundType(model::operations::kFundType fundType);

  private:
    std::shared_ptr<model::operations::iFundSetParameter> mFund;
};

}  // namespace operations
}  // namespace controller
}  // namespace backend

#endif // BACKEND_CONTROLLER_OPERATIONS_SELECTFUND_HPP
