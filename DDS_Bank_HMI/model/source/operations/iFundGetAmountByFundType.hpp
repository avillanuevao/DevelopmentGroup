#ifndef MODEL_OPERATIONS_IFUNDGETAMOUNTBYFUNDTYPE_HPP
#define MODEL_OPERATIONS_IFUNDGETAMOUNTBYFUNDTYPE_HPP

#include <operations/kFundType.hpp>

namespace model
{
namespace operations
{

class iFundGetAmountByFundType
{
  public:
    iFundGetAmountByFundType() = default;

    virtual int getAmount(model::operations::kFundType fundType) const = 0;
};

}  // namespace operations
}  // namespace model

#endif  // MODEL_OPERATIONS_IFUNDGETAMOUNTBYFUNDTYPE_HPP
