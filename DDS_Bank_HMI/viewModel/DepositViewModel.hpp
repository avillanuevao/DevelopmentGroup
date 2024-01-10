#ifndef DEPOSITVIEWMODEL_HPP
#define DEPOSITVIEWMODEL_HPP

#include <model/AllFunds.hpp>
#include <idl/bank.hpp>
#include <utils/SignalPublisher.hpp>
#include <viewModel/signal/DepositMoneySignal.hpp>

namespace viewModel {
    class DepositViewModel: public utils::SignalPublisher<signal::DepositMoneySignal>
    {
    public:
        DepositViewModel(model::AllFunds& allFunds);
        void depositMoney(int amount, FundType fundType);
    private:
        model::AllFunds& m_allFunds;
    };
}

#endif // DEPOSITVIEWMODEL_HPP
