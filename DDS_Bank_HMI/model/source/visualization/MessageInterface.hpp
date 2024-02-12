#ifndef MODEL_VISUALIZATION_MESSAGEINTERFACE_HPP
#define MODEL_VISUALIZATION_MESSAGEINTERFACE_HPP

#include <chrono>

#include <visualization/MessageType.hpp>
#include <visualization/OperationType.hpp>

namespace model
{
namespace visualization
{

class MessageInterface
{
    public:
        MessageInterface(std::time_t date,
                         model::visualization::OperationType operationType,
                         int amount,
                         model::visualization::MessageType messageType);

    private:
        std::time_t m_date;
};

}
}

#endif // MODEL_VISUALIZATION_MESSAGEINTERFACE_HPP
