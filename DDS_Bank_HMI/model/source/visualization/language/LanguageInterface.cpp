#include "LanguageInterface.hpp"

namespace model
{
namespace visualization
{
namespace language
{

std::string LanguageInterface::literalToString(model::visualization::language::Literals literal)
{
    return m_literals[literal];
}

std::string LanguageInterface::literalToString(std::vector<model::visualization::language::Literals> literals, std::vector<std::string> data)
{
    std::string completeSentence;
    int maxNumberValues = 5;

    for (model::visualization::language::Literals literal : literals)
    {
        bool isNotValue = true;

        for(int indexData = 0; indexData < maxNumberValues; indexData++)
        {
            int indexLiterals = indexData + model::visualization::language::Literals::VALUE1;
            bool isValue = literal == model::visualization::language::Literals::_from_index(indexLiterals);

            if(isValue)
            {
                completeSentence += data.at(indexData);
                isNotValue = false;
            }
        }

        if(isNotValue)
        {
            completeSentence += literalToString(literal);
        }

    }

    return "";
}



}
}
}
