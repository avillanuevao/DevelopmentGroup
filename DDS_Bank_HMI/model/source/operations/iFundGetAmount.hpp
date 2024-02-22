#ifndef MODEL_OPERATIONS_IFUNDGETAMOUNT_HPP
#define MODEL_OPERATIONS_IFUNDGETAMOUNT_HPP

#include <operations/kFundType.hpp>

namespace model
{
namespace operations
{

class iFundGetAmount
{
  public:
    iFundGetAmount() = default;

    virtual int getAmount() const = 0;
};

}  // namespace operations
}  // namespace model

#endif  // MODEL_OPERATIONS_IFUNDGETAMOUNT_HPP
