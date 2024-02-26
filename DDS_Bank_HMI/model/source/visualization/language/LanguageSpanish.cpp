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
  mLiterals[model::visualization::language::kLiterals::English]   = "Inglés";
  mLiterals[model::visualization::language::kLiterals::Spanish]   = "Español";
  mLiterals[model::visualization::language::kLiterals::Accept]   = "Aceptar";
  mLiterals[model::visualization::language::kLiterals::AmountDeposit]   = "Cantidad depositar";
  mLiterals[model::visualization::language::kLiterals::AmountWithdraw]   = "Cantidad extraer";
  mLiterals[model::visualization::language::kLiterals::AmountTransfer]   = "Cantidad transferir";
  mLiterals[model::visualization::language::kLiterals::DestinationTransfer]   = "Destino Transferencia";
}

}  // namespace language
}  // namespace visualization
}  // namespace model
