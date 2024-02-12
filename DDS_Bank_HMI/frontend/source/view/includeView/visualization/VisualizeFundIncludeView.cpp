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
    m_visualizeFundViewModel(visualizeFundViewModel),
    m_fundTypeActual(model::operations::FundType::SAVINGS)
{

}

void VisualizeFundIncludeView::recievedSignal(model::operations::signal::UpdatedFundSignal signal)
{
    m_visualizeFundViewModel->updateView(signal.getFundType(), signal.getAmount());
}

void VisualizeFundIncludeView::recievedSignal(model::operations::signal::UpdatedFundTypeSignal signal)
{
    m_fundTypeActual = signal.getFundType();
    m_visualizeFundViewModel->updateView();
}


}
}
}
}
