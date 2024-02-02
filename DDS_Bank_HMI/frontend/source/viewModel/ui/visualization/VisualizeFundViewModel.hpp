#ifndef FRONTEND_VIEWMODEL_UI_VISUALIZATION_VISUALIZEFUNDVIEWMODEL_HPP
#define FRONTEND_VIEWMODEL_UI_VISUALIZATION_VISUALIZEFUNDVIEWMODEL_HPP

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
        VisualizeFundViewModel();

        void updateView(int amount);
};

}
}
}
}
#endif // FRONTEND_VIEWMODEL_UI_VISUALIZATION_VISUALIZEFUNDVIEWMODEL_HPP
