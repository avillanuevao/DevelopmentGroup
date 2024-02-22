#ifndef MODEL_OPERATIONS_IFUNDSETPARAMETERS_HPP
#define MODEL_OPERATIONS_IFUNDSETPARAMETERS_HPP

#include <operations/kFundType.hpp>

namespace model
{
namespace operations
{

class iFundSetParameter
{
  public:
    iFundSetParameter() = default;

    virtual void setAmount(int amount) = 0;
    virtual void setFundType(model::operations::kFundType fundType) = 0;
};

}  // namespace operations
}  // namespace model

#endif  // MODEL_OPERATIONS_IFUNDSETPARAMETERS_HPP
