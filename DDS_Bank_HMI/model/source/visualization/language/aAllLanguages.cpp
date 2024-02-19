#include "aAllLanguages.hpp"

namespace model
{
namespace visualization
{
namespace language
{

aAllLanguages::aAllLanguages(model::visualization::language::LanguagesAvailables actualLanguage):
    m_actualLanguage(actualLanguage)
{

}

std::shared_ptr<aLanguage> aAllLanguages::getLanguageDictionary(model::visualization::language::LanguagesAvailables language)
{
    return m_languages[language];
}

std::string aAllLanguages::literalToString(model::visualization::language::kLiterals literal)
{
    return getActualLanguage()->literalToString(literal);
}

std::string aAllLanguages::literalToString(std::vector<model::visualization::language::kLiterals> literals, std::vector<std::string> data)
{
    return getActualLanguage()->literalToString(literals, data);
}

std::shared_ptr<aLanguage> aAllLanguages::getActualLanguage()
{
    return getLanguageDictionary(m_actualLanguage);
}


}
}
}


