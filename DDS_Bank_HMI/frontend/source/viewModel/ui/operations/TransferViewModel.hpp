#ifndef FRONTEND_VIEWMODEL_UI_OPERATION_TRANSFERVIEWMODEL_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATION_TRANSFERVIEWMODEL_HPP

#include <memory>

#include <utils/source/designPattern/SignalPublisher.hpp>
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

class TransferViewModel :
        public utils::designPattern::SignalPublisher<frontend::viewModel::signal::TransferedMoneySignal>


{
    public:
        TransferViewModel();

        void transferMoney(model::FundType destinationFundType, int amount);
};

}
}
}
}

#endif // FRONTEND_VIEWMODEL_UI_OPERATION_TRANSFERVIEWMODEL_HPP
