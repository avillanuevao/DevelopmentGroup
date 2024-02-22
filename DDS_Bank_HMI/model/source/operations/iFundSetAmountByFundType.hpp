#ifndef MODEL_OPERATIONS_IFUNDSETAMOUNTBYFUNDTYPE_HPP
#define MODEL_OPERATIONS_IFUNDSETAMOUNTBYFUNDTYPE_HPP

#include <operations/kFundType.hpp>

namespace model
{
namespace operations
{

class iFundSetAmountByFundType
{
  public:
    iFundSetAmountByFundType() = default;

    virtual void setAmount(model::operations::kFundType fundType, int amount) = 0;
};

}  // namespace operations
}  // namespace model

#endif  // MODEL_OPERATIONS_IFUNDSETAMOUNTBYFUNDTYPE_HPP
