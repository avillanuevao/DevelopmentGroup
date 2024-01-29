#ifndef DEPOSITMODEL_HPP
#define DEPOSITMODEL_HPP

#include <map>
#include <stdexcept>

#include <Fund.hpp>
#include <FundType.hpp>
#include <signal/MoneyDepositedSignal.hpp>
#include <signal/MoneyWithdrawnSignal.hpp>
#include <signal/MoneyTransferedSignal.hpp>
#include <designPattern/SignalPublisher.hpp>

namespace model {

        public utils::designPattern::SignalPublisher<model::signal::MoneyDepositedSignal>,
        public utils::designPattern::SignalPublisher<model::signal::MoneyWithdrawnSignal>
        public utils::designPattern::SignalPublisher<model::signal::MoneyTransferedSignal>
{
    public:
        AllFunds();

        void increaseAmount(model::FundType fundType, int amount) noexcept(false);
        void decreaseAmount(model::FundType fundType, int amount) noexcept(false);
        void transferAmount(model::FundType originFundType, model::FundType destinationFundType, int amount);
        int getAmount(model::FundType fundType) const;
        void setAmount(model::FundType fundType, int newAmount);

    private:
        std::map<model::FundType, Fund> m_funds;
};

}

#endif // DEPOSITMODEL_HPP
