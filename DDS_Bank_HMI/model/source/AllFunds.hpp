#ifndef DEPOSITMODEL_HPP
#define DEPOSITMODEL_HPP

#include <map>
#include <stdexcept>
#include <memory>

#include <Fund.hpp>
#include <FundType.hpp>
#include <FundInterface.hpp>
#include <FundTransferAmountInterface.hpp>

namespace model
{

class AllFunds :
        public model::FundInterface,
        public model::FundTransferAmountInterface
{
    public:
        AllFunds(model::FundType actualFund);

        void increaseAmount(int amount) override;
        void decreaseAmount(int amount) override;
        void transferAmount(model::FundType fundTypeDestination, int amount) override;

        int getAmount() const override;
        model::FundType getFundType() const;
        void setAmount(int amount) override;
        void setFundType(model::FundType fundType) override;

    private:
        std::shared_ptr<model::FundInterface> getFund(model::FundType  m_actualFund);
        std::shared_ptr<model::FundInterface> getActualFund();
        std::shared_ptr<model::FundInterface> getFund(model::FundType  m_actualFund) const;
        std::shared_ptr<model::FundInterface> getActualFund() const;
        void initFund(FundType fundType);
        void notifySubscribersFund(model::FundType fundType, int amount);
        void notifySubscribersFundType(model::FundType fundType);

        std::map<model::FundType, std::shared_ptr<model::FundInterface>> m_funds;
        model::FundType m_actualFund;

};

}

#endif // DEPOSITMODEL_HPP
