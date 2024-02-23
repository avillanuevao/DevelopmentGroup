#ifndef MODEL_OPERATIONS_IFUNDGETPARAMETERS_HPP
#define MODEL_OPERATIONS_IFUNDGETPARAMETERS_HPP

#include <operations/kFundType.hpp>

namespace model
{
namespace operations
{

class iFundGetParameters
{
  public:
    iFundGetParameters() = default;

    virtual int getAmount() const = 0;
    virtual model::operations::kFundType getFundType() const = 0;
};

}  // namespace operations
}  // namespace model

#endif  // MODEL_OPERATIONS_IFUNDGETPARAMETERS_HPP
