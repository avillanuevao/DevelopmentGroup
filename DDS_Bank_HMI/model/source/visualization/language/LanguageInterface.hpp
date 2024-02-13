#ifndef MODEL_VISUALIZATION_LANGUAGE_LANGUAGEINTERFACE_HPP
#define MODEL_VISUALIZATION_LANGUAGE_LANGUAGEINTERFACE_HPP

#include <map>
#include <vector>

#include <visualization/language/Literals.hpp>

namespace model
{
namespace visualization
{
namespace language
{

class LanguageInterface
{
    public:
        LanguageInterface() = default;

        std::string literalToString(model::visualization::language::Literals literal);
        std::string literalToString(std::vector<model::visualization::language::Literals> literals,
                                            std::vector<std::string> data = {});

    protected:
        virtual void initLiterals() = 0;

        std::map<model::visualization::language::Literals, std::string> m_literals;

};

}
}
}

#endif // MODEL_VISUALIZATION_LANGUAGE_LANGUAGEINTERFACE_HPP
