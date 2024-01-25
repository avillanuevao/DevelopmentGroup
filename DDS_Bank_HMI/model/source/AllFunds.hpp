#ifndef DEPOSITMODEL_HPP
#define DEPOSITMODEL_HPP

#include <map>
#include <stdexcept>

#include <Fund.hpp>
#include <FundType.hpp>
#include <signal/MoneyDepositedSignal.hpp>
#include <designPattern/SignalPublisher.hpp>

namespace model {

class AllFunds : public utils::designPattern::SignalPublisher<model::signal::MoneyDepositedSignal>
{
    public:
        AllFunds();

        void increaseAmount(model::FundType fundType, int amount);
        int getAmount(model::FundType fundType) const;
        void setAmount(model::FundType fundType, int newAmount);

    private:
        std::map<model::FundType, Fund> m_funds;
};

}

#endif // DEPOSITMODEL_HPP
