#ifndef DEPOSITVIEWMODEL_HPP
#define DEPOSITVIEWMODEL_HPP

#include <model/FundType.hpp>
#include <model/AllFunds.hpp>

namespace viewModel {
    class DepositViewModel
    {
    public:
        DepositViewModel(model::AllFunds& allFunds);
        void depositMoney(int amount, model::FundType fundType);
    private:
        model::AllFunds& m_allFunds;
    };
}

#endif // DEPOSITVIEWMODEL_HPP
