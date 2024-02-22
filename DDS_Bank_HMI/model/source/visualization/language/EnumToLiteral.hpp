#ifndef ENUMTOLITERAL_HPP
#define ENUMTOLITERAL_HPP

#include <map>

#include <visualization/language/kLiterals.hpp>
#include <operations/FundType.hpp>
#include <visualization/message/OperationType.hpp>

class EnumToLiteral
{
  public:
    EnumToLiteral();

    model::visualization::language::kLiterals toLiteral(model::operations::FundType fundType) const;
    model::visualization::language::kLiterals toLiteral(model::visualization::message::OperationType operationType) const;

  private:
    std::map<model::operations::FundType, model::visualization::language::kLiterals> mFundTypeToLiteral;
    std::map<model::visualization::message::OperationType, model::visualization::language::kLiterals> mOperationTypeToLiteral;
};

#endif // ENUMTOLITERAL_HPP
