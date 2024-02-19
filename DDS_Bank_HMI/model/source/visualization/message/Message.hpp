#ifndef MODEL_VISUALIZATION_MESSAGE_HPP
#define MODEL_VISUALIZATION_MESSAGE_HPP

#include <iomanip>
#include <sstream>

#include <visualization/message/MessageInterface.hpp>

namespace model
{
namespace visualization
{
namespace message
{

class Message:
        public model::visualization::message::MessageInterface
{
    public:
        Message(std::time_t date,
                model::visualization::message::MessageType messageType,
                std::vector<model::visualization::language::Literals> literals,
                std::vector<std::string> data);
};


}
}
}

#endif // MODEL_VISUALIZATION_MESSAGE_HPP
