#ifndef DEPOSITVIEWMODEL_HPP
#define DEPOSITVIEWMODEL_HPP

#include <memory>

#include <model/source/AllFunds.hpp>
#include <model/source/FundType.hpp>
#include <model/source/signal/MoneyDepositedSignal.hpp>
#include <utils/designPattern/SignalPublisher.hpp>
#include <utils/designPattern/SignalSubscriber.hpp>
#include <frontend/viewModel/signal/DepositMoneySignal.hpp>
#include <frontend/viewModel/signal/MoneyDepositedSignal.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

class DepositViewModel:
        public utils::designPattern::SignalPublisher<viewModel::signal::DepositMoneySignal>,
        public utils::designPattern::SignalSubscriber<model::signal::MoneyDepositedSignal>,
        public utils::designPattern::SignalPublisher<viewModel::signal::MoneyDepositedSignal>
{
    public:
        DepositViewModel(std::shared_ptr<model::AllFunds> allFunds);
        void depositMoney(model::FundType fundType, int amount);
        void update(model::signal::MoneyDepositedSignal signal);

    private:
        std::shared_ptr<model::AllFunds> m_allFunds;
};

}
}
}
}
#endif // DEPOSITVIEWMODEL_HPP
