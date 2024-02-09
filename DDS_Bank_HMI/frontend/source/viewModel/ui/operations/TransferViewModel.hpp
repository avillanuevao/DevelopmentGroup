#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_TRANSFERVIEWMODEL_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_TRANSFERVIEWMODEL_HPP

#include <memory>

#include <utils/source/designPattern/SignalPublisher.hpp>
#include <model/source/operations/FundType.hpp>
#include <frontend/source/viewModel/ui/operations/signal/TransferedMoneySignal.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

class TransferViewModel :
        public utils::designPattern::SignalPublisher<viewModel::ui::operations::signal::TransferedMoneySignal>


{
    public:
        TransferViewModel();

        void transferMoney(model::operations::FundType destinationFundType, int amount);
};

}
}
}
}

#endif // FRONTEND_VIEWMODEL_UI_OPERATIONS_TRANSFERVIEWMODEL_HPP
