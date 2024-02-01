#ifndef DEPOSITMODEL_HPP
#define DEPOSITMODEL_HPP

#include <map>
#include <stdexcept>

#include <Fund.hpp>
#include <FundType.hpp>
#include <signal/UpdatedModelSignal.hpp>
#include <designPattern/SignalPublisher.hpp>
#include <AllFundsDDSInterface.hpp>
#include <FundInterface.hpp>

namespace model
{

class AllFunds :
        public model::AllFundsDDSInterface,
        public model::FundInterface,
        public utils::designPattern::SignalPublisher<model::signal::UpdatedModelSignal>
{
    public:
        AllFunds(model::FundType actualFund);

        void increaseAmount(int amount) noexcept(false) override;
        void decreaseAmount(int amount) noexcept(false) override;
        int getAmount() const override;
        void setAmount(int amount) override;
        void setAmount(FundType fundType, int amount) override;

        void transferAmount(model::FundType originFundType, model::FundType destinationFundType, int amount);
        void setActualFund(model::FundType newActualFund);

    private:
        std::shared_ptr<model::FundInterface> getFund(model::FundType  m_actualFund);
        std::shared_ptr<model::FundInterface> getActualFund();
        std::shared_ptr<model::FundInterface> getFund(model::FundType  m_actualFund) const;
        std::shared_ptr<model::FundInterface> getActualFund() const;
        void initFund(FundType fundType);
        void notifySubscriber(model::FundType fundType, int amount);

        std::map<model::FundType, std::shared_ptr<model::FundInterface>> m_funds;
        model::FundType m_actualFund;

};

}

#endif // DEPOSITMODEL_HPP
