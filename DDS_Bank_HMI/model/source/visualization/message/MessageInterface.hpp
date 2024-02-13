#ifndef MODEL_VISUALIZATION_MESSAGE_MESSAGEINTERFACE_HPP
#define MODEL_VISUALIZATION_MESSAGE_MESSAGEINTERFACE_HPP

#include <chrono>
#include <memory>

#include <visualization/message/MessageType.hpp>
#include <visualization/message/OperationType.hpp>
#include <visualization/message/OperationInterface.hpp>
#include <visualization/message/OperationSingleFund.hpp>
#include <visualization/message/OperationDualFund.hpp>

namespace model
{
namespace visualization
{
namespace message
{

class MessageInterface
{
    public:
        MessageInterface(std::time_t date,
                         model::visualization::message::MessageType messageType,
                         model::visualization::message::OperationType operationType,
                         model::operations::FundType fundOrigin,
                         model::operations::FundType fundDestination,
                         int amount);

        virtual std::string toString() = 0;

    protected:
        std::time_t m_date;
        model::visualization::message::MessageType m_messageType;
        std::unique_ptr<model::visualization::message::OperationInterface> m_operation;
};

}
}
}

#endif // MODEL_VISUALIZATION_MESSAGE_MESSAGEINTERFACE_HPP
