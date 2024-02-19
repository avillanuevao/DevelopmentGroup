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
    std::vector<model::visualization::language::Literals> literals (createLiterals(operationType, originFundType, destinationFundType));
    std::vector<std::string> data {std::to_string(amount)};

    model::visualization::message::MessageInterface message(date, messageType, literals, data);

    m_allMessages->addMessage(message);
}

std::vector<model::visualization::language::Literals> ShowMessageController::createLiterals(
        model::visualization::message::OperationType operationType,
        model::operations::FundType originFundType,
        model::operations::FundType destinationFundType)
{
    std::vector<model::visualization::language::Literals> literals;

    model::visualization::language::Literals literalOperation = toLiteral(operationType);
    model::visualization::language::Literals literalOriginFundType = toLiteral(originFundType);

    if(operationType == +model::visualization::message::OperationType::DEPOSIT ||
            operationType == +model::visualization::message::OperationType::WITHDRAW)
    {
        literals = {literalOriginFundType, literalOperation, model::visualization::language::Literals::VALUE1};
    }
    else if(operationType == +model::visualization::message::OperationType::TRANSFER)
    {
        model::visualization::language::Literals literalDestinationFundType = toLiteral(destinationFundType);

        literals = {literalOriginFundType, literalOperation, literalDestinationFundType, model::visualization::language::Literals::VALUE1};

    }

    return literals;
}

model::visualization::language::Literals ShowMessageController::toLiteral(model::operations::FundType fundType)
{
    return model::visualization::language::Literals::_from_string(fundType._to_string());

}

model::visualization::language::Literals ShowMessageController::toLiteral(model::visualization::message::OperationType operationType)
{
    return model::visualization::language::Literals::_from_string(operationType._to_string());
}

}
}
}
