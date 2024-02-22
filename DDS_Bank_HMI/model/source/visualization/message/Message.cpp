#include "Message.hpp"

namespace model
{
namespace visualization
{
namespace message
{

Message::Message(std::time_t date, model::visualization::message::kMessageType messageType,
                 std::vector<model::visualization::language::kLiterals> literals,
                 std::vector<std::string> data) :
  model::visualization::message::aMessage(date, messageType, literals, data)
{

}

}  // namespace message
}  // namespace visualization
}  // namespace model
