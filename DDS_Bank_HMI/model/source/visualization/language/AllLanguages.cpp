#include "AllLanguages.hpp"

namespace model
{
namespace visualization
{
namespace language
{

AllLanguages::AllLanguages(model::visualization::language::kLanguagesAvailables actualLanguage) :
  model::visualization::language::aAllLanguages(actualLanguage)
{
  initAllLanguages();
}

void AllLanguages::initAllLanguages()
{
  mLanguages[model::visualization::language::kLanguagesAvailables::Spanish] =
      std::make_shared<model::visualization::language::LanguageSpanish>();

  mLanguages[model::visualization::language::kLanguagesAvailables::English] =
      std::make_shared<model::visualization::language::LanguageEnglish>();
}

}  // namespace language
}  // namespace visualization
}  // namespace model
