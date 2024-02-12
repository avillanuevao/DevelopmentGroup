#ifndef MODEL_VISUALIZATION_OPERATIONINTERFACE_HPP
#define MODEL_VISUALIZATION_OPERATIONINTERFACE_HPP

#include <operations/FundType.hpp>
#include <visualization/OperationType.hpp>

namespace model
{
namespace visualization
{

class OperationInterface
{
    public:
        OperationInterface(model::visualization::OperationType operationType,
                           int amount,
                           model::operations::FundType fundType);

        virtual std::string toString() = 0;

    protected:
        model::visualization::OperationType m_operationType;
        int m_amount;
        model::operations::FundType m_fundType;
};

}
}

#endif // MODEL_VISUALIZATION_OPERATIONINTERFACE_HPP
