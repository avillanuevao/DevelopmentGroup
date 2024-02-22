#include "AllLanguages.hpp"

namespace model
{
namespace visualization
{
namespace language
{

AllLanguages::AllLanguages(model::visualization::language::kLanguagesAvailables actualLanguage):
    model::visualization::language::aAllLanguages(actualLanguage)
{
    initAllLanguages();
}

void AllLanguages::initAllLanguages()
{
    m_languages[model::visualization::language::kLanguagesAvailables::kSpanish] =
            std::make_shared<model::visualization::language::LanguageSpanish>();

    m_languages[model::visualization::language::kLanguagesAvailables::kEnglish] =
            std::make_shared<model::visualization::language::LanguageEnglish>();
}

}
}
}
