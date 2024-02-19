#include "AllLanguages.hpp"

namespace model
{
namespace visualization
{
namespace language
{

AllLanguages::AllLanguages(model::visualization::language::LanguagesAvailables actualLanguage):
    model::visualization::language::aAllLanguages(actualLanguage)
{
    initAllLanguages();
}

void AllLanguages::initAllLanguages()
{
    m_languages[model::visualization::language::LanguagesAvailables::SPANISH] =
            std::make_shared<model::visualization::language::LanguageSpanish>();

    m_languages[model::visualization::language::LanguagesAvailables::ENGLISH] =
            std::make_shared<model::visualization::language::LanguageEnglish>();
}

}
}
}
