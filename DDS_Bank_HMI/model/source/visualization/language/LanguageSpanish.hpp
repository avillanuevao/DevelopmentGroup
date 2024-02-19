#ifndef MODEL_VISUALIZATION_LANGUAGE_SPANISH_HPP
#define MODEL_VISUALIZATION_LANGUAGE_SPANISH_HPP

#include <visualization/language/aLanguage.hpp>

namespace model
{
namespace visualization
{
namespace language
{

class LanguageSpanish:
        public model::visualization::language::aLanguage
{
    public:
        LanguageSpanish();

    private:
        void initLiterals();
};

}
}
}

#endif // MODEL_VISUALIZATION_LANGUAGE_SPANISH_HPP
