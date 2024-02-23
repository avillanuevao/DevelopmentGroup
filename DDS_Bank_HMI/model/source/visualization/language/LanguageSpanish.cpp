#include "LanguageSpanish.hpp"

namespace model
{
namespace visualization
{
namespace language
{

LanguageSpanish::LanguageSpanish()
{
  initLiterals();
}

void LanguageSpanish::initLiterals()
{
  mLiterals[model::visualization::language::kLiterals::Fund]      = "fondo";
  mLiterals[model::visualization::language::kLiterals::Deposit]   = "depósito";
  mLiterals[model::visualization::language::kLiterals::Withdraw]  = "extracción";
  mLiterals[model::visualization::language::kLiterals::Transfer]  = "transferencia";
  mLiterals[model::visualization::language::kLiterals::Success]   = "éxito";
  mLiterals[model::visualization::language::kLiterals::Failure]   = "fallo";
  mLiterals[model::visualization::language::kLiterals::Warning]   = "advertencia";
  mLiterals[model::visualization::language::kLiterals::Savings]   = "ahorro";
  mLiterals[model::visualization::language::kLiterals::Housing]   = "hogar";
}

}  // namespace language
}  // namespace visualization
}  // namespace model
