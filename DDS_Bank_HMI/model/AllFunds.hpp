#ifndef DEPOSITMODEL_HPP
#define DEPOSITMODEL_HPP

#include <map>
#include <model/Fund.hpp>
#include <model/FundType.hpp>
#include <utils/SignalPublisher.hpp>
#include <model/signal/MoneyDepositedSignal.hpp>

namespace model {

//typedef std::tuple<FundType, Fund> FundTuple;

class AllFunds : public utils::SignalPublisher<model::MoneyDepositedSignal>
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
