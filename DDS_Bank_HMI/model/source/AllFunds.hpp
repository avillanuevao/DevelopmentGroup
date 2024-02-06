#ifndef DEPOSITMODEL_HPP
#define DEPOSITMODEL_HPP

#include <map>
#include <stdexcept>
#include <memory>

#include <Fund.hpp>
#include <FundType.hpp>
#include <FundInterface.hpp>
#include <FundTransferAmountInterface.hpp>
#include <FundGetAmountByFundTypeInterface.hpp>
#include <FundDecreaseAmountByFundTypeInterface.hpp>
#include <FundSetAmountByFundTypeInterface.hpp>

namespace model
{

class AllFunds :
        public model::FundInterface,
        public model::FundTransferAmountInterface,
        public model::FundGetAmountByFundTypeInterface,
        public model::FundDecreaseAmountByFundTypeInterface,
        public model::FundSetAmountByFundTypeInterface
{
    public:
        AllFunds(model::FundType actualFund);

        void increaseAmount(int amount) override;
        void decreaseAmount(int amount) override;
        void decreaseAmount(model::FundType fundType, int amount);
        void transferAmount(model::FundType fundTypeDestination, int amount) override;

        int getAmount(model::FundType fundType) const override;
        int getAmount() const override;
        model::FundType getFundType() const override;
        void setAmount(int amount) override;
        void setAmount(model::FundType fundType, int amount);
        void setFundType(model::FundType fundType) override;

    private:
        std::shared_ptr<model::FundInterface> getFund(model::FundType  m_actualFund);
        std::shared_ptr<model::FundInterface> getFund(model::FundType  m_actualFund) const;
        std::shared_ptr<model::FundInterface> getActualFund();
        std::shared_ptr<model::FundInterface> getActualFund() const;
        void initFund(FundType fundType);
        void notifySubscribersFund(model::FundType fundType, int amount);
        void notifySubscribersFundType(model::FundType fundType);

        std::map<model::FundType, std::shared_ptr<model::FundInterface>> m_funds;
        model::FundType m_actualFund;

};

}

#endif // DEPOSITMODEL_HPP
