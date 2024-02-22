#ifndef MODEL_VISUALIZATION_LANGUAGE_ALANGUAGE_HPP
#define MODEL_VISUALIZATION_LANGUAGE_ALANGUAGE_HPP

#include <map>
#include <vector>

#include <visualization/language/kLiterals.hpp>

namespace model
{
namespace visualization
{
namespace language
{

class aLanguage
{
    public:
        aLanguage();

        virtual std::string literalToString(model::visualization::language::kLiterals literal);
        virtual std::string literalToString(std::vector<model::visualization::language::kLiterals> literals,
                                            std::vector<std::string> data = {});


    protected:
        std::map<model::visualization::language::kLiterals, std::string> m_literals;

    private:
        void initValues();

        std::map<model::visualization::language::kLiterals, size_t> m_values;

};

}
}
}

#endif // MODEL_VISUALIZATION_LANGUAGE_ALANGUAGE_HPP
