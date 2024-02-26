#ifndef MODEL_VISUALIZATION_LANGUAGE_ENUMTOLITERAL_HPP
#define MODEL_VISUALIZATION_LANGUAGE_ENUMTOLITERAL_HPP

#include <map>
#include <stdexcept>

#include <operations/kFundType.hpp>
#include <visualization/language/kLiterals.hpp>
#include <visualization/message/kOperationType.hpp>

namespace model
{
namespace visualization
{
namespace language
{

class EnumToLiteral
{
  public:
    EnumToLiteral();

    model::visualization::language::kLiterals toLiteral(model::operations::kFundType fundType);
    model::visualization::language::kLiterals toLiteral(
        model::visualization::message::kOperationType operationType);
};

}  // namespace language
}  // namespace visualization
}  // namespace models

#endif  // MODEL_VISUALIZATION_LANGUAGE_ENUMTOLITERAL_HPP
