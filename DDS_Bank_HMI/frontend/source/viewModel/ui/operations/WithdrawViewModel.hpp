#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_WITHDRAWVIEWMODEL_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_WITHDRAWVIEWMODEL_HPP

#include <model/source/AllFunds.hpp>
#include <model/source/signal/MoneyWithdrawnSignal.hpp>
#include <utils/source/designPattern/SignalPublisher.hpp>
#include <frontend/source/viewModel/signal/WithdrawnMoneySignal.hpp>
#include <frontend/source/viewModel/signal/MoneyWithdrawnSignal.hpp>


namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

class WithdrawViewModel:
        public utils::designPattern::SignalPublisher<viewModel::signal::WithdrawnMoneySignal>,
        public utils::designPattern::SignalSubscriber<model::signal::MoneyWithdrawnSignal>,
        public utils::designPattern::SignalPublisher<viewModel::signal::MoneyWithdrawnSignal>
{
    public:
        WithdrawViewModel(std::shared_ptr<model::AllFunds> allFunds);

        void update(model::signal::MoneyWithdrawnSignal signal);
        void withdrawMoney(model::FundType fundType, int amount);

    private:
        std::shared_ptr<model::AllFunds> m_allFunds;

};

}
}
}
}
#endif // FRONTEND_VIEWMODEL_UI_OPERATIONS_WITHDRAWVIEWMODEL_HPP
