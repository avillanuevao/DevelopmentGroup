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
    m_literals[model::visualization::language::Literals::FUND]      = "fondo";
    m_literals[model::visualization::language::Literals::DEPOSIT]   = "depósito";
    m_literals[model::visualization::language::Literals::WITHDRAW]  = "extracción";
    m_literals[model::visualization::language::Literals::TRANSFER]  = "transferencia";
    m_literals[model::visualization::language::Literals::SUCCESS]   = "éxito";
    m_literals[model::visualization::language::Literals::FAILURE]   = "fallo";
    m_literals[model::visualization::language::Literals::WARNING]   = "advertencia";
    m_literals[model::visualization::language::Literals::SAVINGS]   = "ahorro";
    m_literals[model::visualization::language::Literals::HOUSING]   = "hogar";
}

}
}
}
