#include "VisualizeFundIncludeView.hpp"

namespace frontend
{
namespace view
{
namespace includeView
{
namespace visualization
{

VisualizeFundIncludeView::VisualizeFundIncludeView(std::shared_ptr<viewModel::ui::visualization::VisualizeFundViewModel> visualizeFundViewModel) :
    m_visualizeFundViewModel(visualizeFundViewModel)
{
}

void VisualizeFundIncludeView::update(model::signal::UpdatedFundSignal signal)
{
    m_visualizeFundViewModel->updateView(signal.getAmount());
}


}
}
}
}
