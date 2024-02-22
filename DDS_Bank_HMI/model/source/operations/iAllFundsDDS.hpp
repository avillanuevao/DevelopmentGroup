#ifndef MODEL_OPERATIONS_IALLFUNDSDDS_HPP
#define MODEL_OPERATIONS_IALLFUNDSDDS_HPP

#include <operations/kFundType.hpp>

namespace model
{
namespace operations
{

class iAllFundsDDS
{
  public:
    iAllFundsDDS() = default;

    virtual void setAmount(model::operations::kFundType fundType, int amount) = 0;
};

}  // namespace operations
}  // namespace model

#endif  // MODEL_OPERATIONS_IALLFUNDSDDS_HPP
