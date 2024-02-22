#ifndef FRONTEND_VIEW_INCLUDEVIEW_VISUALIZATION_VISUALIZEFUNDINCLUDEVIEW_HPP
#define FRONTEND_VIEW_INCLUDEVIEW_VISUALIZATION_VISUALIZEFUNDINCLUDEVIEW_HPP

#include <memory>

#include <model/source/operations/signal/UpdatedFundType.hpp>
#include <model/source/operations/signal/UpdatedFund.hpp>
#include <frontend/source/viewModel/ui/visualization/VisualizeFund.hpp>
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
        public utils::designPattern::SignalSubscriber<model::operations::signal::UpdatedFund>,
        public utils::designPattern::SignalSubscriber<model::operations::signal::UpdatedFundType>
{
    public:
        VisualizeFundIncludeView(std::shared_ptr<viewModel::ui::visualization::VisualizeFundViewModel> visualizeFundViewModel);

        void recievedSignal(model::operations::signal::UpdatedFund signal);
        void recievedSignal(model::operations::signal::UpdatedFundType signal);

    private:
        std::shared_ptr<viewModel::ui::visualization::VisualizeFundViewModel> m_visualizeFundViewModel;

        model::operations::kFundType m_fundTypeActual;

};

}
}
}
}


#endif // FRONTEND_VIEW_INCLUDEVIEW_VISUALIZATION_VISUALIZEFUNDINCLUDEVIEW_HPP
