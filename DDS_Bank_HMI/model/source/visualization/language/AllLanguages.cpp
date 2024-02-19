#include "AllLanguages.hpp"

namespace model
{
namespace visualization
{
namespace language
{

AllLanguages::AllLanguages()
{
    initAllLanguages();
}

std::shared_ptr<LanguageInterface> AllLanguages::getLanguageDictionary(
        model::visualization::language::LanguagesAvailables language)
{
    return m_languages[language];
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
