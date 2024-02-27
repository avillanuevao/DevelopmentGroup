#include "SelectLanguage.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace visualization
{

SelectLanguage::SelectLanguage(std::shared_ptr<model::visualization::language::iSetLanguage> language) :
  mLanguage(language)
{

}

void SelectLanguage::selectLanguage(model::visualization::language::kLanguagesAvailables language)
{
  mLanguage->setLanguage(language);
}

}  // namespace visualization
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend
