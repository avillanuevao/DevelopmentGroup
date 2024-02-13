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

class AllLanguagesInterface
{
    public:
        AllLanguagesInterface() = default;

        virtual std::shared_ptr<model::visualization::language::LanguageInterface> getLanguageDictionary(
                model::visualization::language::LanguagesAvailables language) = 0;

    protected:
        std::map<model::visualization::language::LanguagesAvailables,
                 std::shared_ptr<model::visualization::language::LanguageInterface>> m_languages;
};

}
}
}

#endif // MODEL_VISUALIZATION_LANGUAGE_ALLLANGUAGESINTERFACE_HPP
