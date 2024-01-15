#ifndef DEPOSITMODEL_HPP
#define DEPOSITMODEL_HPP

#include <map>

#include <idl/bank.hpp>
#include <model/Fund.hpp>
#include <model/signal/MoneyDepositedSignal.hpp>
#include <utils/designPattern/SignalPublisher.hpp>

namespace model {

//typedef std::tuple<FundType, Fund> FundTuple;

class AllFunds : public utils::designPattern::SignalPublisher<model::signal::MoneyDepositedSignal>
{
    public:
        AllFunds();

        void increaseAmount(FundType fundType, int amount);
        int getAmount(FundType fundType) const;
        void setAmount(FundType fundType, int newAmount);

    private:
        std::map<FundType, Fund> m_funds;
};

}

#endif // DEPOSITMODEL_HPP
