#ifndef MODEL_VISUALIZATION_MESSAGE_OPERATIONINTERFACE_HPP
#define MODEL_VISUALIZATION_MESSAGE_OPERATIONINTERFACE_HPP

#include <operations/FundType.hpp>
#include <visualization/message/OperationType.hpp>

namespace model
{
namespace visualization
{
namespace message
{

class OperationInterface
{
    public:
        OperationInterface(model::visualization::message::OperationType operationType,
                           int amount,
                           model::operations::FundType fundType);

        virtual std::string toString() = 0;

    protected:
        model::visualization::message::OperationType m_operationType;
        int m_amount;
        model::operations::FundType m_fundType;
};

}
}
}

#endif // MODEL_VISUALIZATION_MESSAGE_OPERATIONINTERFACE_HPP
