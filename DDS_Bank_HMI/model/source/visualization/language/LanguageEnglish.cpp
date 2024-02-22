#include "LanguageEnglish.hpp"

namespace model
{
namespace visualization
{
namespace language
{

LanguageEnglish::LanguageEnglish()
{
  initLiterals();
}

void LanguageEnglish::initLiterals()
{
  mLiterals[model::visualization::language::kLiterals::Fund]      = "fund";
  mLiterals[model::visualization::language::kLiterals::Deposit]   = "deposit";
  mLiterals[model::visualization::language::kLiterals::Withdraw]  = "withdraw";
  mLiterals[model::visualization::language::kLiterals::Transfer]  = "transfer";
  mLiterals[model::visualization::language::kLiterals::Success]   = "success";
  mLiterals[model::visualization::language::kLiterals::Failure]   = "failure";
  mLiterals[model::visualization::language::kLiterals::Warning]   = "warning";
  mLiterals[model::visualization::language::kLiterals::Savings]   = "savings";
  mLiterals[model::visualization::language::kLiterals::Housing]   = "housing";
}

}  // namespace language
}  // namespace visualization
}  // namespace model
