#include "Visualize.hpp"

namespace frontend
{
namespace view
{
namespace includeView
{
namespace visualization
{

Visualize::Visualize(std::shared_ptr<viewModel::ui::visualization::Visualize> visualize) :
  mVisualize(visualize)
{

}

void Visualize::recievedSignal(model::visualization::language::signal::UpdatedLanguage signal)
{
  mVisualize->updatedLanguage();
}

}  // namespace visualization
}  // namespace includeView
}  // namespace view
}  // namespace frontend
