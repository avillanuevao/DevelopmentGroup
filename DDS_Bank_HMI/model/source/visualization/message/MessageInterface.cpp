#include "MessageInterface.hpp"

namespace model
{
namespace visualization
{
namespace message
{

MessageInterface::MessageInterface(std::time_t date,
                                   model::visualization::message::MessageType messageType,
                                   std::vector<model::visualization::language::Literals> literals):
    m_date(date),
    m_messageType(messageType),
    m_literals(literals)
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

const std::vector<model::visualization::language::Literals> &MessageInterface::getLiterals() const
{
    return m_literals;
}


}
}
}
