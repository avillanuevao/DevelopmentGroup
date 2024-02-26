#include "Visualize.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace visualization
{

Visualize::Visualize()
{

}

void Visualize::updatedLanguage()
{
  frontend::viewModel::ui::visualization::signal::UpdatedLanguage signal;

  notifySubscribers(signal);
}

}  // namespace visualization
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend
