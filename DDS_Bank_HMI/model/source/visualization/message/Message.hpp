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
                model::visualization::message::OperationType operationType,
                model::operations::FundType fundOrigin,
                model::operations::FundType fundDestination,
                int amount);

        std::string toString() override;

    private:
        std::string dateToString();
        std::string messageTypeToString();
};

}
}
}

#endif // MODEL_VISUALIZATION_MESSAGE_HPP
