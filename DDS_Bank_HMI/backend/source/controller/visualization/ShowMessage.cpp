#include "ShowMessage.hpp"

namespace backend
{
namespace controller
{
namespace visualization
{

ShowMessage::ShowMessage(std::shared_ptr<model::visualization::message::aAllMessages> allMessages) :
  m_allMessages(allMessages)
{

}

void ShowMessage::addMessage(time_t date, model::visualization::message::kMessageType messageType,
                             model::visualization::message::kOperationType operationType, int amount,
                             model::operations::kFundType originFundType,
                             model::operations::kFundType destinationFundType)
{
  std::vector<model::visualization::language::kLiterals> literals (
        createLiterals(operationType, originFundType, destinationFundType));
  std::vector<std::string> data {std::to_string(amount)};

  model::visualization::message::aMessage message(date, messageType, literals, data);

  m_allMessages->addMessage(message);
}

std::vector<model::visualization::language::kLiterals> ShowMessage::createLiterals(
    model::visualization::message::kOperationType operationType, model::operations::kFundType originFundType,
    model::operations::kFundType destinationFundType)
{
  std::vector<model::visualization::language::kLiterals> literals;

  model::visualization::language::kLiterals literalOperation = toLiteral(operationType);
  model::visualization::language::kLiterals literalOriginFundType = toLiteral(originFundType);

  if(operationType == +model::visualization::message::kOperationType::Deposit ||
     operationType == +model::visualization::message::kOperationType::Withdraw)
  {
    literals = {literalOriginFundType, literalOperation, model::visualization::language::kLiterals::Value1};
  }
  else if(operationType == +model::visualization::message::kOperationType::Transfer)
  {
    model::visualization::language::kLiterals literalDestinationFundType = toLiteral(destinationFundType);

    literals = {literalOriginFundType, literalOperation, literalDestinationFundType,
                model::visualization::language::kLiterals::Value1};
  }

  return literals;
}

model::visualization::language::kLiterals ShowMessage::toLiteral(model::operations::kFundType fundType)
{
  //TODO: Cambiar esto, es una guarreria
  std::string kLiteral = "k";
  kLiteral += fundType._to_string();

  return model::visualization::language::kLiterals::_from_string_nocase(kLiteral.c_str());
}

model::visualization::language::kLiterals ShowMessage::toLiteral(model::visualization::message::kOperationType operationType)
{
  //TODO: Cambiar esto, es una guarreria
  std::string kLiteral = "k";
  kLiteral += operationType._to_string();

  return model::visualization::language::kLiterals::_from_string_nocase(kLiteral.c_str());
}

}  // namespace visualization
}  // namespace controller
}  // namespace backend
