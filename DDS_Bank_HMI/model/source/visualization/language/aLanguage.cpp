#include "aLanguage.hpp"

namespace model
{
namespace visualization
{
namespace language
{

aLanguage::aLanguage()
{
  initValues();
}

std::string aLanguage::literalToString(model::visualization::language::kLiterals literal)
{
  return mLiterals[literal];
}

std::string aLanguage::literalToString(std::vector<model::visualization::language::kLiterals> literals,
                                       std::vector<std::string> data)
{
  std::string completeSentence;

  for (size_t index = 0; index < literals.size(); ++index)
  {
    model::visualization::language::kLiterals literal = literals[index];

    if (mLiterals.find(literal) != mLiterals.end())
    {
      completeSentence += literalToString(literal);
    }
    else if (mValues.find(literal) != mValues.end())
    {
      if(data.size() == 0)
      {
        throw std::logic_error("Data vector missing");
      }
      completeSentence += data.at(mValues[literal]);
    }
    if (index != literals.size() - 1)
    {
      completeSentence += " ";
    }
  }

  return completeSentence;
}

void aLanguage::initValues()
{
  int indexData = 0;
  int firtsValue = model::visualization::language::kLiterals::Value1;
  int lastValue = model::visualization::language::kLiterals::Value5;

  for(int indexValue = firtsValue; indexValue < lastValue; indexValue++)
  {
    mValues[model::visualization::language::kLiterals::_from_index(indexValue)] = indexData;

    indexData++;
  }
}

}  // namespace language
}  // namespace visualization
}  // namespace model
