#ifndef MODEL_VISUALIZATION_LANGUAGE_AALLLANGUAGES_HPP
#define MODEL_VISUALIZATION_LANGUAGE_AALLLANGUAGES_HPP

#include <map>
#include <memory>

#include <visualization/language/kLanguagesAvailables.hpp>
#include <visualization/language/aLanguage.hpp>
#include <visualization/language/iSetLanguage.hpp>

namespace model
{
namespace visualization
{
namespace language
{

class aAllLanguages:
        public model::visualization::language::aLanguage,
        public model::visualization::language::iSetLanguage
{
    public:
        aAllLanguages(model::visualization::language::kLanguagesAvailables actualLanguage);

        virtual std::shared_ptr<model::visualization::language::aLanguage> getLanguageDictionary(
                model::visualization::language::kLanguagesAvailables language);

        std::string literalToString(model::visualization::language::kLiterals literal) override;
        std::string literalToString(std::vector<model::visualization::language::kLiterals> literals, std::vector<std::string> data) override;

        virtual void setLanguage(model::visualization::language::kLanguagesAvailables newLanguage) override;

    protected:
        std::shared_ptr<model::visualization::language::aLanguage> getActualLanguage();

        model::visualization::language::kLanguagesAvailables m_actualLanguage;
        std::map<model::visualization::language::kLanguagesAvailables,
                 std::shared_ptr<model::visualization::language::aLanguage>> m_languages;

};

}
}
}

#endif // MODEL_VISUALIZATION_LANGUAGE_AALLLANGUAGES_HPP
