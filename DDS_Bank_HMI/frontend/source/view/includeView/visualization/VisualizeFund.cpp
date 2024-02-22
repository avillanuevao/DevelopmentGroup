#include "VisualizeFund.hpp"

namespace frontend
{
namespace view
{
namespace includeView
{
namespace visualization
{

VisualizeFund::VisualizeFund(std::shared_ptr<viewModel::ui::visualization::VisualizeFund> visualizeFund) :
    mVisualizeFundViewModel(visualizeFund),
    mFundTypeActual(model::operations::kFundType::Savings)
{

}

void VisualizeFund::recievedSignal(model::operations::signal::UpdatedFund signal)
{
    mVisualizeFundViewModel->updateView(signal.getFundType(), signal.getAmount());
}

void VisualizeFund::recievedSignal(model::operations::signal::UpdatedFundType signal)
{
    mFundTypeActual = signal.getFundType();
    mVisualizeFundViewModel->updateView();
}

}  // namespace visualization
}  // namespace includeView
}  // namespace view
}  // namespace frontend
