#ifndef MODEL_VISUALIZATION_LANGUAGE_SPANISH_HPP
#define MODEL_VISUALIZATION_LANGUAGE_SPANISH_HPP

#include <visualization/language/LanguageInterface.hpp>

namespace model
{
namespace visualization
{
namespace language
{

class LanguageSpanish:
        public model::visualization::language::LanguageInterface
{
    public:
        LanguageSpanish();

    private:
        void initLiterals() override;
};

}
}
}

#endif // MODEL_VISUALIZATION_LANGUAGE_SPANISH_HPP
