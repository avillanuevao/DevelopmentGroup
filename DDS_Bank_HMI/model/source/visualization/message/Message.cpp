#include "Message.hpp"

namespace model
{
namespace visualization
{
namespace message
{

Message::Message(std::time_t date,
                 model::visualization::message::MessageType messageType,
                 model::visualization::message::OperationType operationType,
                 model::operations::FundType fundOrigin,
                 model::operations::FundType fundDestination,
                 int amount):
    model::visualization::message::MessageInterface(date, messageType, operationType, fundOrigin, fundDestination, amount)
{

}

std::string Message::toString()
{
    std::string completeMessage = dateToString() + " - " + messageTypeToString();

    return completeMessage;
}

std::string Message::dateToString()
{
    std::stringstream stringStream;
    stringStream << std::put_time(std::localtime(&m_date), "%Y/%m/%d %H:%M");

    return stringStream.str();
}

std::string Message::messageTypeToString()
{
    std::string completeMessage;

    switch (m_messageType)
    {
        case model::visualization::message::MessageType::SUCCESS:
        {
            completeMessage += " Operation completed successfully: " + m_operation->toString();
            break;
        }
        case model::visualization::message::MessageType::FAILURE:
        {
            completeMessage += " The operation could not be completed.";
            // TODO: habría que añadir el porque falla
            break;
        }
        case model::visualization::message::MessageType::WARNING:
        {
            break;
        }
    }

    return completeMessage;
}

}
}
}
