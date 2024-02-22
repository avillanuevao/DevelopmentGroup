#include "ShowMessageController.hpp"

namespace backend
{
namespace controller
{
namespace visualization
{

ShowMessageController::ShowMessageController(std::shared_ptr<model::visualization::message::AllMessagesInterface> allMessages) :
    m_allMessages(allMessages)
{

}

void ShowMessageController::addMessage(time_t date,
                                       model::visualization::message::MessageType messageType,
                                       model::visualization::message::OperationType operationType,
                                       int amount,
                                       model::operations::FundType originFundType,
                                       model::operations::FundType destinationFundType)
{
    std::vector<model::visualization::language::kLiterals> literals (createLiterals(operationType, originFundType, destinationFundType));
    std::vector<std::string> data {std::to_string(amount)};

    model::visualization::message::MessageInterface message(date, messageType, literals, data);

    m_allMessages->addMessage(message);
}

std::vector<model::visualization::language::kLiterals> ShowMessageController::createLiterals(
        model::visualization::message::OperationType operationType,
        model::operations::FundType originFundType,
        model::operations::FundType destinationFundType)
{
    std::vector<model::visualization::language::kLiterals> literals;

    model::visualization::language::kLiterals literalOperation = toLiteral(operationType);
    model::visualization::language::kLiterals literalOriginFundType = toLiteral(originFundType);

    if(operationType == +model::visualization::message::OperationType::DEPOSIT ||
            operationType == +model::visualization::message::OperationType::WITHDRAW)
    {
        literals = {literalOriginFundType, literalOperation, model::visualization::language::kLiterals::kValue1};
    }
    else if(operationType == +model::visualization::message::OperationType::TRANSFER)
    {
        model::visualization::language::kLiterals literalDestinationFundType = toLiteral(destinationFundType);

        literals = {literalOriginFundType, literalOperation, literalDestinationFundType, model::visualization::language::kLiterals::kValue1};

    }

    return literals;
}

model::visualization::language::kLiterals ShowMessageController::toLiteral(model::operations::FundType fundType)
{
    //TODO: Cambiar esto, es una guarreria
    std::string kLiteral = "k";
    kLiteral += fundType._to_string();

    return model::visualization::language::kLiterals::_from_string_nocase(kLiteral.c_str());
}

model::visualization::language::kLiterals ShowMessageController::toLiteral(model::visualization::message::OperationType operationType)
{
    //TODO: Cambiar esto, es una guarreria
    std::string kLiteral = "k";
    kLiteral += operationType._to_string();

    return model::visualization::language::kLiterals::_from_string_nocase(kLiteral.c_str());
}

}
}
}
