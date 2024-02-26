#include "EnumToLiteral.hpp"

namespace model
{
namespace visualization
{
namespace language
{
//TODO: Sustituir mapa por switch, ya que better enum complejo mapa

EnumToLiteral::EnumToLiteral()
{

}

model::visualization::language::kLiterals EnumToLiteral::toLiteral(model::operations::kFundType fundType)
{
  switch (fundType)
  {
    case model::operations::kFundType::Savings:
      return model::visualization::language::kLiterals::Savings;
      break;
    case model::operations::kFundType::Housing:
      return model::visualization::language::kLiterals::Housing;
      break;
    case model::operations::kFundType::None:
      return model::visualization::language::kLiterals::Savings;
      break;
  }
}

model::visualization::language::kLiterals EnumToLiteral::toLiteral(
    model::visualization::message::kOperationType operationType)
{
  switch (operationType)
  {
    case model::visualization::message::kOperationType::Deposit:
      return model::visualization::language::kLiterals::Deposit;
      break;
    case model::visualization::message::kOperationType::Withdraw:
      return model::visualization::language::kLiterals::Withdraw;
      break;
    case model::visualization::message::kOperationType::Transfer:
      return model::visualization::language::kLiterals::Transfer;
      break;
  }
}

}  // namespace language
}  // namespace visualization
}  // namespace model
