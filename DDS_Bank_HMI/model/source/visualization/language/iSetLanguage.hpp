#ifndef MODEL_VISUALIZATION_LANGUAGE_ISETLANGUAGE_HPP
#define MODEL_VISUALIZATION_LANGUAGE_ISETLANGUAGE_HPP

#include <visualization/language/kLanguagesAvailables.hpp>

namespace model
{
namespace visualization
{
namespace language
{

class iSetLanguage
{
    public:
        iSetLanguage() = default;

        virtual void setLanguage(model::visualization::language::kLanguagesAvailables newLanguage) = 0;
};

}
}
}

#endif // MODEL_VISUALIZATION_LANGUAGE_ISETLANGUAGE_HPP
