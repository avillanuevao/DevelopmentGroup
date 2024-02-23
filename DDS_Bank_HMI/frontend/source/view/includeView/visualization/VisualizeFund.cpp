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
    mViewModel(visualizeFund), mFundTypeActual(model::operations::kFundType::Savings)
{

}

void VisualizeFund::recievedSignal(model::operations::signal::UpdatedFund signal)
{
    mViewModel->updateView(signal.getFundType(), signal.getAmount());
}

void VisualizeFund::recievedSignal(model::operations::signal::UpdatedFundType signal)
{
    mFundTypeActual = signal.getFundType();
    mViewModel->updateView();
}

}  // namespace visualization
}  // namespace includeView
}  // namespace view
}  // namespace frontend
