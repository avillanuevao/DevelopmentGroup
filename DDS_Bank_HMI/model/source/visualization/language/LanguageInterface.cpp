#include "LanguageInterface.hpp"

namespace model
{
namespace visualization
{
namespace language
{

LanguageInterface::LanguageInterface()
{
    initValues();
}

std::string LanguageInterface::literalToString(model::visualization::language::Literals literal)
{
    return m_literals[literal];
}

std::string LanguageInterface::literalToString(std::vector<model::visualization::language::Literals> literals, std::vector<std::string> data)
{
    std::string completeSentence;

    for (size_t index = 0; index < literals.size(); ++index)
    {
        model::visualization::language::Literals literal = literals[index];

        if (m_literals.find(literal) != m_literals.end())
        {
            completeSentence += literalToString(literal);
        } else if (m_values.find(literal) != m_values.end())
        {
            if(data.size() == 0)
            {
                throw std::logic_error("Data vector missing");
            }
            completeSentence += data.at(m_values[literal]);
        }
        if (index != literals.size() - 1)
        {
            completeSentence += " ";
        }
    }

    return completeSentence;
}

void LanguageInterface::initValues()
{
    int indexData = 0;
    int firtsValue = model::visualization::language::Literals::VALUE1;
    int lastValue = model::visualization::language::Literals::VALUE5;

    for(int indexValue = firtsValue; indexValue < lastValue; indexValue++)
    {
        m_values[model::visualization::language::Literals::_from_index(indexValue)] = indexData;

        indexData++;
    }
}



}
}
}
