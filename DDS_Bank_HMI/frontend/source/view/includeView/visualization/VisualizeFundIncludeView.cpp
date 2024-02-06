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
    m_fundTypeActual = model::FundType::SAVINGS;
}

void VisualizeFundIncludeView::update(model::signal::UpdatedFundSignal signal)
{
    m_visualizeFundViewModel->updateView(signal.getFundType(), signal.getAmount());
}

void VisualizeFundIncludeView::update(model::signal::UpdatedFundTypeSignal signal)
{
    m_fundTypeActual = signal.getFundType();
    m_visualizeFundViewModel->updateView();
}


}
}
}
}
