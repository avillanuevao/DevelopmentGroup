#ifndef FRONTEND_VIEWMODEL_UI_VISUALIZATION_VISUALIZEFUND_HPP
#define FRONTEND_VIEWMODEL_UI_VISUALIZATION_VISUALIZEFUND_HPP

#include <frontend/source/viewModel/ui/visualization/signal/VisualizeFund.hpp>
#include <model/source/operations/iFundGetParameters.hpp>
#include <model/source/operations/kFundType.hpp>
#include <utils/source/designPattern/SignalPublisher.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace visualization
{

class VisualizeFund :
    public utils::designPattern::SignalPublisher<frontend::viewModel::ui::visualization::signal::VisualizeFund>
{
  public:
    VisualizeFund(std::shared_ptr<model::operations::iFundGetParameters> fund);

    void updateView();
    void updateView(model::operations::kFundType fundType, int amount);

  private:
    std::shared_ptr<model::operations::iFundGetParameters> mFund;
};

}  // namespace visualization
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend

#endif  // FRONTEND_VIEWMODEL_UI_VISUALIZATION_VISUALIZEFUND_HPP
