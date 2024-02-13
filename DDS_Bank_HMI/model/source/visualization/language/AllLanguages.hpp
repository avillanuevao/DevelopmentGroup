#ifndef MODEL_VISUALIZATION_LANGUAGE_ALLLANGUAGES_HPP
#define MODEL_VISUALIZATION_LANGUAGE_ALLLANGUAGES_HPP

#include <visualization/language/AllLanguagesInterface.hpp>
#include <visualization/language/LanguageSpanish.hpp>
#include <visualization/language/LanguageEnglish.hpp>

namespace model
{
namespace visualization
{
namespace language
{

class AllLanguages:
        public model::visualization::language::AllLanguagesInterface
{
    public:
        AllLanguages();

        std::shared_ptr<model::visualization::language::LanguageInterface> getLanguageDictionary(
                model::visualization::language::LanguagesAvailables language) override;


    private:
        void initAllLanguages();

};

}
}
}

#endif // MODEL_VISUALIZATION_LANGUAGE_ALLLANGUAGES_HPP
