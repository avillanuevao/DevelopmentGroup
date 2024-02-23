#ifndef MODEL_OPERATIONS_FUND_HPP
#define MODEL_OPERATIONS_FUND_HPP

#include <stdexcept>

#include <operations/iFund.hpp>
#include <operations/kFundType.hpp>

namespace model
{
namespace operations
{

class Fund :
    public model::operations::iFund
{
  public:
    Fund(model::operations::kFundType fundType, int amount);

    void increaseAmount(int amount) override;
    void decreaseAmount(int amount) override;

    int getAmount() const override;
    void setAmount(int amount) override;
    model::operations::kFundType getFundType() const override;
    void setFundType(model::operations::kFundType fundType) override;

  private:
    model::operations::kFundType mFundType;
    int mAmount;
};

}  // namespace operations
}  // namespace model

#endif  // MODEL_OPERATIONS_FUND_HPP
