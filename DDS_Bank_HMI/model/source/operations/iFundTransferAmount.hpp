#ifndef MODEL_OPERATIONS_IFUNDTRANSFERAMOUNT_HPP
#define MODEL_OPERATIONS_IFUNDTRANSFERAMOUNT_HPP

#include <operations/kFundType.hpp>

namespace model
{
namespace operations
{

class iFundTransferAmount
{
  public:
    iFundTransferAmount() = default;

    virtual void transferAmount(model::operations::kFundType fundTypeDestination, int amount) = 0;
};

}  // namespace operations
}  // namespace model

#endif  // MODEL_OPERATIONS_IFUNDTRANSFERAMOUNT_HPP
