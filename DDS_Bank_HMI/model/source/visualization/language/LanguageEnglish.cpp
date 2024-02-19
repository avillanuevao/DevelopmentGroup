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
    m_literals[model::visualization::language::kLiterals::kFund]      = "fund";
    m_literals[model::visualization::language::kLiterals::kDeposit]   = "deposit";
    m_literals[model::visualization::language::kLiterals::kWithdraw]  = "withdraw";
    m_literals[model::visualization::language::kLiterals::kTransfer]  = "transfer";
    m_literals[model::visualization::language::kLiterals::kSuccess]   = "success";
    m_literals[model::visualization::language::kLiterals::kFailure]   = "failure";
    m_literals[model::visualization::language::kLiterals::kWarning]   = "warning";
    m_literals[model::visualization::language::kLiterals::kSavings]   = "savings";
    m_literals[model::visualization::language::kLiterals::kHousing]   = "housing";
}

}
}
}
