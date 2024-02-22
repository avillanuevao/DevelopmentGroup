#ifndef MODEL_VISUALIZATION_MESSAGE_HPP
#define MODEL_VISUALIZATION_MESSAGE_HPP

#include <iomanip>
#include <sstream>

#include <visualization/message/aMessage.hpp>

namespace model
{
namespace visualization
{
namespace message
{

class Message :
    public model::visualization::message::aMessage
{
  public:
    Message(std::time_t date, model::visualization::message::kMessageType messageType,
            std::vector<model::visualization::language::kLiterals> literals, std::vector<std::string> data);
};

}  // namespace message
}  // namespace visualization
}  // namespace model

#endif // MODEL_VISUALIZATION_MESSAGE_HPP
