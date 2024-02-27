#include "SelectLanguage.hpp"

namespace frontend
{
namespace view
{
namespace ui
{
namespace visualization
{


SelectLanguage::SelectLanguage(std::shared_ptr<viewModel::ui::visualization::SelectLanguage> viewModel,
                               QQmlApplicationEngine& engine, QObject* parent) :
  mViewModel(viewModel), mEngine(engine), mParent(parent)
{

}

void SelectLanguage::setLanguage(QString language)
{
  model::visualization::language::kLanguagesAvailables literal =
      model::visualization::language::kLanguagesAvailables::_from_string_nocase(language.toStdString().c_str());
  mViewModel->selectLanguage(literal);
}

}  // namespace visualization
}  // namespace ui
}  // namespace view
}  // namespace frontend
