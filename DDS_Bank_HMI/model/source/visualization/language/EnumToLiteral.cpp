#include "EnumToLiteral.hpp"

EnumToLiteral::EnumToLiteral()
{
  mFundTypeToLiteral[model::operations::FundType::SAVINGS] = model::visualization::language::kLiterals::kSavings;
}

model::visualization::language::kLiterals EnumToLiteral::toLiteral(model::operations::FundType fundType) const
{
//  return mFundTypeToLiteral[fundType];
}

model::visualization::language::kLiterals EnumToLiteral::toLiteral(model::visualization::message::OperationType operationType) const
{

}
