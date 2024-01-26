#ifndef TRANSFERVIEWMODEL_HPP
#define TRANSFERVIEWMODEL_HPP

#include <memory>

#include <utils/source/designPattern/SignalPublisher.hpp>
#include <model/source/AllFunds.hpp>
#include <model/source/FundType.hpp>
#include <frontend/source/viewModel/signal/TransferedMoneySignal.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

class TransferViewModel : public utils::designPattern::SignalPublisher<frontend::viewModel::signal::TransferedMoneySignal>
{
    public:
        TransferViewModel(std::shared_ptr<model::AllFunds> allFunds);

        void transferMoney(model::FundType originFundType, model::FundType destinationFundType, int amount);
    private:
        std::shared_ptr<model::AllFunds> m_allFunds;
};

}
}
}
}

#endif // TRANSFERVIEWMODEL_HPP
