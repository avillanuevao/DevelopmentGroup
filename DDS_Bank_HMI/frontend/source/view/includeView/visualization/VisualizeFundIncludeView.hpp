#ifndef FRONTEND_VIEW_INCLUDEVIEW_VISUALIZATION_VISUALIZEFUNDINCLUDEVIEW_HPP
#define FRONTEND_VIEW_INCLUDEVIEW_VISUALIZATION_VISUALIZEFUNDINCLUDEVIEW_HPP

#include <memory>

#include <model/source/operations/signal/UpdatedFundTypeSignal.hpp>
#include <model/source/operations/signal/UpdatedFundSignal.hpp>
#include <frontend/source/viewModel/ui/visualization/VisualizeFundViewModel.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>

namespace frontend
{
namespace view
{
namespace includeView
{
namespace visualization
{

class VisualizeFundIncludeView :
        public utils::designPattern::SignalSubscriber<model::operations::signal::UpdatedFundSignal>,
        public utils::designPattern::SignalSubscriber<model::operations::signal::UpdatedFundTypeSignal>
{
    public:
        VisualizeFundIncludeView(std::shared_ptr<viewModel::ui::visualization::VisualizeFundViewModel> visualizeFundViewModel);

        void update(model::operations::signal::UpdatedFundSignal signal);
        void update(model::operations::signal::UpdatedFundTypeSignal signal);

    private:
        std::shared_ptr<viewModel::ui::visualization::VisualizeFundViewModel> m_visualizeFundViewModel;

        model::operations::FundType m_fundTypeActual;

};

}
}
}
}


#endif // FRONTEND_VIEW_INCLUDEVIEW_VISUALIZATION_VISUALIZEFUNDINCLUDEVIEW_HPP
