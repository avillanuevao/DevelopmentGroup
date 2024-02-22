#ifndef MODEL_OPERATIONS_SIGNAL_UPDATEDFUNDTYPE_HPP
#define MODEL_OPERATIONS_SIGNAL_UPDATEDFUNDTYPE_HPP

#include <operations/kFundType.hpp>

namespace model
{
namespace operations
{
namespace signal
{

class UpdatedFundType
{
  public:
    UpdatedFundType(model::operations::kFundType fundType);

    model::operations::kFundType getFundType() const;
    void setFundType(model::operations::kFundType newFundType);

  private:
    model::operations::kFundType mFundType;
};

}  // namespace signal
}  // namespace operations
}  // namespace model

#endif  // MODEL_OPERATIONS_SIGNAL_UPDATEDFUNDTYPESIGNAL_HPP
