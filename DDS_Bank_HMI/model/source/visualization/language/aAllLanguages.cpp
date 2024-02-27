#include "aAllLanguages.hpp"

namespace model
{
namespace visualization
{
namespace language
{

aAllLanguages::aAllLanguages(model::visualization::language::kLanguagesAvailables actualLanguage) :
  mActualLanguage(actualLanguage)
{

}

std::string aAllLanguages::literalToString(model::visualization::language::kLiterals literal)
{
  return getActualLanguage()->literalToString(literal);
}

std::string aAllLanguages::literalToString(std::vector<model::visualization::language::kLiterals> literals,
                                           std::vector<std::string> data)
{
  return getActualLanguage()->literalToString(literals, data);
}

std::shared_ptr<aLanguage> aAllLanguages::getLanguage(
    model::visualization::language::kLanguagesAvailables language)
{
  return mLanguages[language];
}

void aAllLanguages::setLanguage(model::visualization::language::kLanguagesAvailables newLanguage)
{
  mActualLanguage = newLanguage;

  model::visualization::language::signal::UpdatedLanguage signal;
  notifySubscribers(signal);
}

std::shared_ptr<aLanguage> aAllLanguages::getActualLanguage()
{
  return getLanguage(mActualLanguage);
}

}  // namespace language
}  // namespace visualization
}  // namespace model


