#ifndef MODEL_VISUALIZATION_LANGUAGE_ALLLANGUAGES_HPP
#define MODEL_VISUALIZATION_LANGUAGE_ALLLANGUAGES_HPP

#include <visualization/language/aAllLanguages.hpp>
#include <visualization/language/LanguageEnglish.hpp>
#include <visualization/language/LanguageSpanish.hpp>

namespace model
{
namespace visualization
{
namespace language
{

class AllLanguages :
    public model::visualization::language::aAllLanguages
{
  public:
    AllLanguages(model::visualization::language::kLanguagesAvailables actualLanguage);

  private:
    void initAllLanguages();
};

}  // namespace language
}  // namespace visualization
}  // namespace model

#endif // MODEL_VISUALIZATION_LANGUAGE_ALLLANGUAGES_HPP
