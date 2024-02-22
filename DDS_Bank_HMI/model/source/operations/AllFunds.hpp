#ifndef MODEL_OPERATIONS_ALLFUNDS_HPP
#define MODEL_OPERATIONS_ALLFUNDS_HPP

#include <map>
#include <memory>
#include <stdexcept>

#include <operations/Fund.hpp>
#include <operations/iFund.hpp>
#include <operations/iFundGetAmountByFundType.hpp>
#include <operations/iFundSetAmountByFundType.hpp>
#include <operations/iFundTransferAmount.hpp>
#include <operations/kFundType.hpp>

namespace model
{
namespace operations
{

class AllFunds :
    public model::operations::iFund,
    public model::operations::iFundGetAmountByFundType,
    public model::operations::iFundSetAmountByFundType,
    public model::operations::iFundTransferAmount
{
  public:
    AllFunds(model::operations::kFundType actualFund);

    void increaseAmount(int amount) override;
    void decreaseAmount(int amount) override;
    void transferAmount(model::operations::kFundType fundTypeDestination, int amount) override;

    int getAmount() const override;
    int getAmount(model::operations::kFundType fundType) const override;
    void setAmount(int amount) override;
    void setAmount(model::operations::kFundType fundType, int amount) override;
    model::operations::kFundType getFundType() const override;
    void setFundType(model::operations::kFundType fundType) override;

  private:
    void initFund(model::operations::kFundType fundType);
    void notifySubscribersFund(model::operations::kFundType fundType, int amount);
    void notifySubscribersFundType(model::operations::kFundType fundType);

//    std::shared_ptr<model::operations::iFund> getFund(model::operations::kFundType  m_actualFund);
    std::shared_ptr<model::operations::iFund> getFund(model::operations::kFundType  m_actualFund) const;
//    std::shared_ptr<model::operations::iFund> getActualFund();
    std::shared_ptr<model::operations::iFund> getActualFund() const;

    std::map<model::operations::kFundType, std::shared_ptr<model::operations::iFund>> mFunds;
    model::operations::kFundType mActualFund;

};

}  // namespace operations
}  // namespace model

#endif  // MODEL_OPERATIONS_ALLFUNDS_HPP
