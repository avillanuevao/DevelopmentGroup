#include "AllLanguagesInterface.hpp"

namespace model
{
namespace visualization
{
namespace language
{

AllLanguagesInterface::AllLanguagesInterface(model::visualization::language::LanguagesAvailables actualLanguage):
    m_actualLanguage(actualLanguage)
{

}

std::shared_ptr<LanguageInterface> AllLanguagesInterface::getLanguageDictionary(model::visualization::language::LanguagesAvailables language)
{
    return m_languages[language];
}

std::string AllLanguagesInterface::literalToString(model::visualization::language::Literals literal)
{
    return getActualLanguage()->literalToString(literal);
}

std::string AllLanguagesInterface::literalToString(std::vector<model::visualization::language::Literals> literals, std::vector<std::string> data)
{
    return getActualLanguage()->literalToString(literals, data);
}

std::shared_ptr<LanguageInterface> AllLanguagesInterface::getActualLanguage()
{
    return getLanguageDictionary(m_actualLanguage);
}


}
}
}


