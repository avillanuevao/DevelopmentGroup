#ifndef MODEL_VISUALIZATION_MESSAGEINTERFACE_HPP
#define MODEL_VISUALIZATION_MESSAGEINTERFACE_HPP

#include <chrono>
#include <memory>

#include <visualization/MessageType.hpp>
#include <visualization/OperationType.hpp>
#include <visualization/OperationInterface.hpp>
#include <visualization/OperationSingleFund.hpp>
#include <visualization/OperationDualFund.hpp>

namespace model
{
namespace visualization
{

class MessageInterface
{
    public:
        MessageInterface(std::time_t date,
                         model::visualization::MessageType messageType,
                         model::visualization::OperationType operationType,
                         model::operations::FundType fundOrigin,
                         model::operations::FundType fundDestination,
                         int amount);

        virtual std::string toString() = 0;

    protected:
        std::time_t m_date;
        model::visualization::MessageType m_messageType;
        std::unique_ptr<model::visualization::OperationInterface> m_operation;
};

}
}

#endif // MODEL_VISUALIZATION_MESSAGEINTERFACE_HPP
