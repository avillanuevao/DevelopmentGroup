#ifndef MODEL_VISUALIZATION_LANGUAGE_ALLLANGUAGESINTERFACE_HPP
#define MODEL_VISUALIZATION_LANGUAGE_ALLLANGUAGESINTERFACE_HPP

#include <map>
#include <memory>

#include <visualization/language/LanguagesAvailables.hpp>
#include <visualization/language/LanguageInterface.hpp>

namespace model
{
namespace visualization
{
namespace language
{

class AllLanguagesInterface:
        public  model::visualization::language::LanguageInterface
{
    public:
        AllLanguagesInterface(model::visualization::language::LanguagesAvailables actualLanguage);

        virtual std::shared_ptr<model::visualization::language::LanguageInterface> getLanguageDictionary(
                model::visualization::language::LanguagesAvailables language);

        std::string literalToString(model::visualization::language::Literals literal) override;
        std::string literalToString(std::vector<model::visualization::language::Literals> literals, std::vector<std::string> data) override;

    protected:
        std::shared_ptr<model::visualization::language::LanguageInterface> getActualLanguage();

        model::visualization::language::LanguagesAvailables m_actualLanguage;
        std::map<model::visualization::language::LanguagesAvailables,
                 std::shared_ptr<model::visualization::language::LanguageInterface>> m_languages;

};

}
}
}

#endif // MODEL_VISUALIZATION_LANGUAGE_ALLLANGUAGESINTERFACE_HPP
