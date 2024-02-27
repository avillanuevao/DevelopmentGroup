#ifndef FRONTEND_VIEW_INCLUDEVIEW_VISUALIZATION_VISUALIZE_HPP
#define FRONTEND_VIEW_INCLUDEVIEW_VISUALIZATION_VISUALIZE_HPP

#include <memory>

#include <utils/source/designPattern/SignalSubscriber.hpp>
#include <model/source/visualization/language/signal/UpdatedLanguage.hpp>
#include <frontend/source/viewModel/ui/visualization/Visualize.hpp>

namespace frontend
{
namespace view
{
namespace includeView
{
namespace visualization
{

class Visualize :
    public utils::designPattern::SignalSubscriber<model::visualization::language::signal::UpdatedLanguage>
{
  public:
    Visualize(std::shared_ptr<frontend::viewModel::ui::visualization::Visualize> visualize);

    void recievedSignal(model::visualization::language::signal::UpdatedLanguage signal) override;

  private:
    std::shared_ptr<frontend::viewModel::ui::visualization::Visualize> mViewModel;
};

#endif  // FRONTEND_VIEW_INCLUDEVIEW_VISUALIZATION_VISUALIZE_HPP

}  // namespace visualization
}  // namespace includeView
}  // namespace view
}  // namespace frontend
