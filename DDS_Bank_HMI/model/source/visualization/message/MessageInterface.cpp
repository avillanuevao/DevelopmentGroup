#include "MessageInterface.hpp"

namespace model
{
namespace visualization
{
namespace message
{

MessageInterface::MessageInterface(model::visualization::message::MessageInterface const &message):
    m_date(message.m_date),
    m_messageType(message.m_messageType),
    m_literals(message.m_literals),
    m_data(message.m_data)
{

}

MessageInterface::MessageInterface(std::time_t date,
                                   model::visualization::message::MessageType messageType,
                                   std::vector<model::visualization::language::kLiterals> literals, std::vector<std::string> data):
    m_date(date),
    m_messageType(messageType),
    m_literals(literals),
    m_data(data)
{

}

std::time_t MessageInterface::getDate() const
{
    return m_date;
}

const model::visualization::message::MessageType &MessageInterface::getMessageType() const
{
    return m_messageType;
}

const std::vector<model::visualization::language::kLiterals> &MessageInterface::getLiterals() const
{
    return m_literals;
}

const std::vector<std::string> &MessageInterface::getData() const
{
    return m_data;
}


}
}
}
