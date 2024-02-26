#ifndef FRONTEND_VIEWMODEL_UI_VISUALIZATION_VISUALIZE_HPP
#define FRONTEND_VIEWMODEL_UI_VISUALIZATION_VISUALIZE_HPP

#include <utils/source/designPattern/SignalPublisher.hpp>
#include <frontend/source/viewModel/ui/visualization/signal/UpdatedLanguage.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace visualization
{

class Visualize :
    public utils::designPattern::SignalPublisher<
    frontend::viewModel::ui::visualization::signal::UpdatedLanguage>
{
  public:
    Visualize();

    void updatedLanguage();
};

}  // namespace visualization
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend

#endif  // FRONTEND_VIEWMODEL_UI_VISUALIZATION_VISUALIZE_HPP
