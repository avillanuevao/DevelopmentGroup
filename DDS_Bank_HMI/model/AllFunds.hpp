#ifndef DEPOSITMODEL_HPP
#define DEPOSITMODEL_HPP

#include <map>

#include <model/Fund.hpp>
#include <model/signal/MoneyDepositedSignal.hpp>
#include <model/FundType.hpp>
#include <utils/designPattern/SignalPublisher.hpp>

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
