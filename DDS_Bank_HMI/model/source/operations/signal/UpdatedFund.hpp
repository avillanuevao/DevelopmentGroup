#ifndef MODEL_OPERATIONS_SIGNAL_UPDATEDFUND_HPP
#define MODEL_OPERATIONS_SIGNAL_UPDATEDFUND_HPP

#include <operations/kFundType.hpp>

namespace  model
{
namespace operations
{
namespace signal
{

class UpdatedFund
{
  public:
    UpdatedFund(model::operations::kFundType fundType, int amount);

    int getAmount() const;
    void setAmount(int newAmount);
    model::operations::kFundType getFundType() const;
    void setFundType(model::operations::kFundType newFundType);

  private:
    model::operations::kFundType mFundType;
    int mAmount;
};

}  // namespace signal
}  // namespace operations
}  // namespace model

#endif  // MODEL_OPERATIONS_SIGNAL_UPDATEDFUNDSIGNAL_HPP
