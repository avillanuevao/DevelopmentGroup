#ifndef FRONTEND_VIEW_INCLUDEVIEW_VISUALIZATION_VISUALIZEFUND_HPP
#define FRONTEND_VIEW_INCLUDEVIEW_VISUALIZATION_VISUALIZEFUND_HPP

#include <memory>

#include <frontend/source/viewModel/ui/visualization/VisualizeFund.hpp>
#include <model/source/operations/kFundType.hpp>
#include <model/source/operations/signal/UpdatedFund.hpp>
#include <model/source/operations/signal/UpdatedFundType.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>

namespace frontend
{
namespace view
{
namespace includeView
{
namespace visualization
{

class VisualizeFund :
    public utils::designPattern::SignalSubscriber<model::operations::signal::UpdatedFund>,
    public utils::designPattern::SignalSubscriber<model::operations::signal::UpdatedFundType>
{
  public:
    VisualizeFund(std::shared_ptr<viewModel::ui::visualization::VisualizeFund> visualizeFund);

    void recievedSignal(model::operations::signal::UpdatedFund signal);
    void recievedSignal(model::operations::signal::UpdatedFundType signal);

  private:
    std::shared_ptr<viewModel::ui::visualization::VisualizeFund> mViewModel;
    model::operations::kFundType mFundTypeActual;
};

}  // namespace visualization
}  // namespace includeView
}  // namespace view
}  // namespace frontend

#endif  // FRONTEND_VIEW_INCLUDEVIEW_VISUALIZATION_VISUALIZEFUND_HPP
