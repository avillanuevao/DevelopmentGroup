#ifndef DEPOSITVIEWMODEL_HPP
#define DEPOSITVIEWMODEL_HPP

#include <memory>

#include <model/AllFunds.hpp>
#include <model/FundType.hpp>
#include <utils/designPattern/SignalPublisher.hpp>
#include <frontend/viewModel/signal/DepositMoneySignal.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

class DepositViewModel:
        public utils::designPattern::SignalPublisher<viewModel::signal::DepositMoneySignal>
{
    public:
        DepositViewModel(std::shared_ptr<model::AllFunds> allFunds);
        void depositMoney(model::FundType fundType, int amount);

    private:
        std::shared_ptr<model::AllFunds> m_allFunds;
};

}
}
}
}
#endif // DEPOSITVIEWMODEL_HPP
