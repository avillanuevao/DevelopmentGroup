#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_SELECTFUNDVIEWMODEL_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_SELECTFUNDVIEWMODEL_HPP

#include <model/source/FundType.hpp>
#include <utils/source/designPattern/SignalPublisher.hpp>
#include <frontend/source/viewModel/ui/operations/signal/SelectFundSignal.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{

class SelectFundViewModel :
        public utils::designPattern::SignalPublisher<frontend::viewModel::ui::operations::signal::SelectFundSignal>
{
    public:
        SelectFundViewModel();

        void selectFund(model::FundType fundType);
};

}
}
}
}
#endif // FRONTEND_VIEWMODEL_UI_OPERATIONS_SELECTFUNDVIEWMODEL_HPP