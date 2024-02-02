#ifndef FRONTEND_VIEW_INCLUDEVIEW_VISUALIZATION_VISUALIZEFUNDINCLUDEVIEW_HPP
#define FRONTEND_VIEW_INCLUDEVIEW_VISUALIZATION_VISUALIZEFUNDINCLUDEVIEW_HPP

#include <memory>

#include <model/source/signal/UpdatedFundSignal.hpp>
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
        public utils::designPattern::SignalSubscriber<model::signal::UpdatedFundSignal>
{
    public:
        VisualizeFundIncludeView(std::shared_ptr<viewModel::ui::visualization::VisualizeFundViewModel> visualizeFundViewModel);

        void update(model::signal::UpdatedFundSignal signal);

    private:
        std::shared_ptr<viewModel::ui::visualization::VisualizeFundViewModel> m_visualizeFundViewModel;

};

}
}
}
}


#endif // FRONTEND_VIEW_INCLUDEVIEW_VISUALIZATION_VISUALIZEFUNDINCLUDEVIEW_HPP
