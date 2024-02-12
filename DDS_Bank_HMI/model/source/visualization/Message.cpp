#include "Message.hpp"

namespace model
{
namespace visualization
{

Message::Message(std::time_t date,
                 model::visualization::MessageType messageType,
                 model::visualization::OperationType operationType,
                 model::operations::FundType fundOrigin,
                 model::operations::FundType fundDestination,
                 int amount):
    model::visualization::MessageInterface(date, messageType, operationType, fundOrigin, fundDestination, amount)
{

}

std::string Message::toString()
{
    std::string completeMessage = dateToString() + " - " + messageTypeToString();

    return completeMessage;
}

std::string model::visualization::Message::dateToString()
{
    std::stringstream stringStream;
    stringStream << std::put_time(std::localtime(&m_date), "%Y/%m/%d %H:%M");

    return stringStream.str();
}

std::string model::visualization::Message::messageTypeToString()
{
    std::string completeMessage;

    switch (m_messageType)
    {
        case model::visualization::MessageType::SUCCESS:
        {
            completeMessage += " Operation completed successfully: " + m_operation->toString();
            break;
        }
        case model::visualization::MessageType::FAILURE:
        {
            completeMessage += " The operation could not be completed.";
            // TODO: habría que añadir el porque falla
            break;
        }
        case model::visualization::MessageType::WARNING:
        {
            break;
        }
    }

    return completeMessage;
}

}
}
