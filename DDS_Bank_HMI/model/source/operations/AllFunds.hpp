#ifndef MODEL_OPERATIONS_ALLFUNDS_HPP
#define MODEL_OPERATIONS_ALLFUNDS_HPP

#include <map>
#include <stdexcept>
#include <memory>

#include <operations/Fund.hpp>
#include <operations/FundType.hpp>
#include <operations/FundInterface.hpp>
#include <operations/FundTransferAmountInterface.hpp>
#include <operations/FundGetAmountByFundTypeInterface.hpp>
#include <operations/FundSetAmountByFundTypeInterface.hpp>

namespace model
{
namespace operations
{

class AllFunds :
    public model::operations::FundInterface,
    public model::operations::FundTransferAmountInterface,
    public model::operations::FundGetAmountByFundTypeInterface,
    public model::operations::FundSetAmountByFundTypeInterface
{
  public:
    AllFunds(model::operations::FundType actualFund);

    void increaseAmount(int amount) override;
    void decreaseAmount(int amount) override;
    void transferAmount(model::operations::FundType fundTypeDestination, int amount) override;

    int getAmount(model::operations::FundType fundType) const override;
    int getAmount() const override;
    model::operations::FundType getFundType() const override;
    void setAmount(int amount) override;
    void setAmount(model::operations::FundType fundType, int amount) override;
    void setFundType(model::operations::FundType fundType) override;

  private:
    std::shared_ptr<model::operations::FundInterface> getFund(model::operations::FundType  m_actualFund);
    std::shared_ptr<model::operations::FundInterface> getFund(model::operations::FundType  m_actualFund) const;
    std::shared_ptr<model::operations::FundInterface> getActualFund();
    std::shared_ptr<model::operations::FundInterface> getActualFund() const;
    void initFund(FundType fundType);
    void notifySubscribersFund(model::operations::FundType fundType, int amount);
    void notifySubscribersFundType(model::operations::FundType fundType);

    std::map<model::operations::FundType, std::shared_ptr<model::operations::FundInterface>> m_funds;
    model::operations::FundType m_actualFund;

};

}
}

#endif // MODEL_OPERATIONS_ALLFUNDS_HPP
