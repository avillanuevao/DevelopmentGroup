#ifndef MODEL_VISUALIZATION_LANGUAGE_AALLLANGUAGES_HPP
#define MODEL_VISUALIZATION_LANGUAGE_AALLLANGUAGES_HPP

#include <map>
#include <memory>

#include <visualization/language/LanguagesAvailables.hpp>
#include <visualization/language/aLanguage.hpp>

namespace model
{
namespace visualization
{
namespace language
{

class aAllLanguages:
        public  model::visualization::language::aLanguage
{
    public:
        aAllLanguages(model::visualization::language::LanguagesAvailables actualLanguage);

        virtual std::shared_ptr<model::visualization::language::aLanguage> getLanguageDictionary(
                model::visualization::language::LanguagesAvailables language);

        std::string literalToString(model::visualization::language::kLiterals literal) override;
        std::string literalToString(std::vector<model::visualization::language::kLiterals> literals, std::vector<std::string> data) override;

    protected:
        std::shared_ptr<model::visualization::language::aLanguage> getActualLanguage();

        model::visualization::language::LanguagesAvailables m_actualLanguage;
        std::map<model::visualization::language::LanguagesAvailables,
                 std::shared_ptr<model::visualization::language::aLanguage>> m_languages;

};

}
}
}

#endif // MODEL_VISUALIZATION_LANGUAGE_AALLLANGUAGES_HPP
