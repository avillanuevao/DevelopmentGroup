#ifndef FRONTEND_VIEWMODEL_UI_OPERATION_TRANSFERVIEWMODEL_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATION_TRANSFERVIEWMODEL_HPP

#include <memory>

#include <utils/source/designPattern/SignalPublisher.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>
#include <model/source/AllFunds.hpp>
#include <model/source/FundType.hpp>
#include <model/source/signal/MoneyTransferedSignal.hpp>
#include <frontend/source/viewModel/signal/TransferedMoneySignal.hpp>
#include <frontend/source/viewModel/signal/MoneyTransferedSignal.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

class TransferViewModel :
        public utils::designPattern::SignalPublisher<frontend::viewModel::signal::TransferedMoneySignal>,
        public utils::designPattern::SignalSubscriber<model::signal::MoneyTransferedSignal>,
        public utils::designPattern::SignalPublisher<frontend::viewModel::signal::MoneyTransferedSignal>


{
    public:
        TransferViewModel(std::shared_ptr<model::AllFunds> allFunds);

        void transferMoney(model::FundType originFundType, model::FundType destinationFundType, int amount);
        void update(model::signal::MoneyTransferedSignal signal);
    private:
        std::shared_ptr<model::AllFunds> m_allFunds;
};

}
}
}
}

#endif // FRONTEND_VIEWMODEL_UI_OPERATION_TRANSFERVIEWMODEL_HPP
