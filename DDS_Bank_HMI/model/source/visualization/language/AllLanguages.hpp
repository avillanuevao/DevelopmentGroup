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
        AllLanguages(model::visualization::language::LanguagesAvailables actualLanguage);

    private:
        void initAllLanguages();

};

}
}
}

#endif // MODEL_VISUALIZATION_LANGUAGE_ALLLANGUAGES_HPP
