#include "aMessage.hpp"

namespace model
{
namespace visualization
{
namespace message
{

aMessage::aMessage(model::visualization::message::aMessage const &message) :
    mDate(message.mDate), mMessageType(message.mMessageType), mLiterals(message.mLiterals),
    mData(message.mData)
{

}

aMessage::aMessage(std::time_t date, model::visualization::message::kMessageType messageType,
                   std::vector<model::visualization::language::kLiterals> literals,
                   std::vector<std::string> data) :
    mDate(date),
    mMessageType(messageType),
    mLiterals(literals),
    mData(data)
{

}

std::time_t aMessage::getDate() const
{
    return mDate;
}

model::visualization::message::kMessageType aMessage::getMessageType() const
{
    return mMessageType;
}

std::vector<model::visualization::language::kLiterals> aMessage::getLiterals() const
{
    return mLiterals;
}

std::vector<std::string> aMessage::getData() const
{
    return mData;
}

}  // namespace message
}  // namespace visualization
}  // namespace model
