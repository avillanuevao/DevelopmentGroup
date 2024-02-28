#ifndef BACKEND_CONTROLLER_OPERATIONS_SIGNAL_SAVEFUND_HPP
#define BACKEND_CONTROLLER_OPERATIONS_SIGNAL_SAVEFUND_HPP

#include <model/source/operations/kFundType.hpp>

namespace backend
{
namespace controller
{
namespace operations
{
namespace signal
{

class SaveFund
{
  public:
    SaveFund(model::operations::kFundType fundChanged);

    const model::operations::kFundType& getFundChanged() const;

  private:
    model::operations::kFundType mFundChanged;
};

}  // namespace signal
}  // namespace operations
}  // namespace controller
}  // namespace backend

#endif // BACKEND_CONTROLLER_OPERATIONS_SIGNAL_SAVEFUND_HPP
