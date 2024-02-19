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
    m_literals[model::visualization::language::kLiterals::kFund]      = "fondo";
    m_literals[model::visualization::language::kLiterals::kDeposit]   = "depósito";
    m_literals[model::visualization::language::kLiterals::kWithdraw]  = "extracción";
    m_literals[model::visualization::language::kLiterals::kTransfer]  = "transferencia";
    m_literals[model::visualization::language::kLiterals::kSuccess]   = "éxito";
    m_literals[model::visualization::language::kLiterals::kFailure]   = "fallo";
    m_literals[model::visualization::language::kLiterals::kWarning]   = "advertencia";
    m_literals[model::visualization::language::kLiterals::kSavings]   = "ahorro";
    m_literals[model::visualization::language::kLiterals::kHousing]   = "hogar";
}

}
}
}
