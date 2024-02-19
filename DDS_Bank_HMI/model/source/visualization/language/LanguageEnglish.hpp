#ifndef MODEL_VISUALIZATION_LANGUAGE_ENGLISH_HPP
#define MODEL_VISUALIZATION_LANGUAGE_ENGLISH_HPP

#include <visualization/language/aLanguage.hpp>

namespace model
{
namespace visualization
{
namespace language
{

class LanguageEnglish:
        public model::visualization::language::aLanguage
{
    public:
        LanguageEnglish();

    private:
        void initLiterals();
};

}
}
}

#endif // MODEL_VISUALIZATION_LANGUAGE_ENGLISH_HPP
