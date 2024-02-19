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
    m_literals[model::visualization::language::Literals::FUND]      = "fund";
    m_literals[model::visualization::language::Literals::DEPOSIT]   = "deposit";
    m_literals[model::visualization::language::Literals::WITHDRAW]  = "withdraw";
    m_literals[model::visualization::language::Literals::TRANSFER]  = "transfer";
    m_literals[model::visualization::language::Literals::SUCCESS]   = "success";
    m_literals[model::visualization::language::Literals::FAILURE]   = "failure";
    m_literals[model::visualization::language::Literals::WARNING]   = "warning";
    m_literals[model::visualization::language::Literals::SAVINGS]   = "savings";
    m_literals[model::visualization::language::Literals::HOUSING]   = "housing";
}

}
}
}
