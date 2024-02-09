#ifndef FRONTEND_VIEWMODEL_UI_VISUALIZATION_VISUALIZEFUNDVIEWMODEL_HPP
#define FRONTEND_VIEWMODEL_UI_VISUALIZATION_VISUALIZEFUNDVIEWMODEL_HPP

#include <model/source/operations/FundType.hpp>
#include <model/source/operations/FundGetParametersInterface.hpp>
#include <frontend/source/viewModel/ui/visualization/signal/VisualizeFundSignal.hpp>
#include <utils/source/designPattern/SignalPublisher.hpp>

namespace frontend
{
namespace viewModel
{
namespace  ui
{
namespace visualization
{

class VisualizeFundViewModel :
        public utils::designPattern::SignalPublisher<frontend::viewModel::ui::visualization::signal::VisualizeFundSignal>
{
    public:
        VisualizeFundViewModel(std::shared_ptr<model::operations::FundGetParametersInterface> fund);

        void updateView();
        void updateView(model::operations::FundType fundType, int amount);

    private:
        std::shared_ptr<model::operations::FundGetParametersInterface> m_fund;
};

}
}
}
}
#endif // FRONTEND_VIEWMODEL_UI_VISUALIZATION_VISUALIZEFUNDVIEWMODEL_HPP
