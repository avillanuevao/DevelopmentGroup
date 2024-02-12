#ifndef MODEL_VISUALIZATION_MESSAGE_HPP
#define MODEL_VISUALIZATION_MESSAGE_HPP

#include <iomanip>
#include <sstream>

#include <visualization/MessageInterface.hpp>

namespace model
{
namespace visualization
{

class Message:
        public model::visualization::MessageInterface
{
    public:
        Message(std::time_t date,
                model::visualization::MessageType messageType,
                model::visualization::OperationType operationType,
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

#endif // MODEL_VISUALIZATION_MESSAGE_HPP
