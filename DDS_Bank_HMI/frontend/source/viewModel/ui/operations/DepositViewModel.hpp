#ifndef DEPOSITVIEWMODEL_HPP
#define DEPOSITVIEWMODEL_HPP

#include <memory>

#include <model/source/FundType.hpp>
#include <model/source/signal/MoneyDepositedSignal.hpp>
#include <utils/source/designPattern/SignalPublisher.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>
#include <frontend/source/viewModel/signal/DepositMoneySignal.hpp>
#include <frontend/source/viewModel/signal/MoneyDepositedSignal.hpp>

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
        DepositViewModel();
        void depositMoney(model::FundType fundType, int amount);
        void update(model::signal::MoneyDepositedSignal signal);
};

}
}
}
}
#endif // DEPOSITVIEWMODEL_HPP
