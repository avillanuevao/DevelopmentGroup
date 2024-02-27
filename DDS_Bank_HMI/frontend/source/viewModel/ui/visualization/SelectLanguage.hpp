#ifndef FRONTEND_VIEWMODEL_UI_VISUALIZATION_SELECTLANGUAGE_HPP
#define FRONTEND_VIEWMODEL_UI_VISUALIZATION_SELECTLANGUAGE_HPP

#include <memory>

#include <model/source/visualization/language/iSetLanguage.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace visualization
{

class SelectLanguage
{
  public:
    SelectLanguage(std::shared_ptr<model::visualization::language::iSetLanguage> language);

    void selectLanguage(model::visualization::language::kLanguagesAvailables language);

  private:
    std::shared_ptr<model::visualization::language::iSetLanguage> mLanguage;
};

}  // namespace visualization
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend

#endif  // FRONTEND_VIEWMODEL_UI_VISUALIZATION_SELECTLANGUAGE_HPP
