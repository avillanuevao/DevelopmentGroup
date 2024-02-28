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
  mOrderLanguages.push_back(model::visualization::language::kLanguagesAvailables::English);
  mOrderLanguages.push_back(model::visualization::language::kLanguagesAvailables::Spanish);
}

void SelectLanguage::setLanguage(int language)
{
  mViewModel->selectLanguage(mOrderLanguages.at(language));
}

}  // namespace visualization
}  // namespace ui
}  // namespace view
}  // namespace frontend
