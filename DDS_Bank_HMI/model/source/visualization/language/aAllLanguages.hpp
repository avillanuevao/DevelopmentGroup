#ifndef MODEL_VISUALIZATION_LANGUAGE_AALLLANGUAGES_HPP
#define MODEL_VISUALIZATION_LANGUAGE_AALLLANGUAGES_HPP

#include <map>
#include <memory>

#include <visualization/language/aLanguage.hpp>
#include <visualization/language/iSetLanguage.hpp>
#include <visualization/language/kLanguagesAvailables.hpp>

namespace model
{
namespace visualization
{
namespace language
{

class aAllLanguages :
    public model::visualization::language::aLanguage,
    public model::visualization::language::iSetLanguage
{
  public:
    aAllLanguages(model::visualization::language::kLanguagesAvailables actualLanguage);

    std::string literalToString(model::visualization::language::kLiterals literal) override;
    std::string literalToString(std::vector<model::visualization::language::kLiterals> literals,
                                std::vector<std::string> data) override;

    virtual std::shared_ptr<model::visualization::language::aLanguage> getLanguage(
        model::visualization::language::kLanguagesAvailables language);
    void setLanguage(model::visualization::language::kLanguagesAvailables newLanguage) override;

  protected:
    std::shared_ptr<model::visualization::language::aLanguage> getActualLanguage();

    model::visualization::language::kLanguagesAvailables mActualLanguage;
    std::map<model::visualization::language::kLanguagesAvailables,
    std::shared_ptr<model::visualization::language::aLanguage>> mLanguages;
};

}  // namespace language
}  // namespace visualization
}  // namespace model

#endif // MODEL_VISUALIZATION_LANGUAGE_AALLLANGUAGES_HPP
