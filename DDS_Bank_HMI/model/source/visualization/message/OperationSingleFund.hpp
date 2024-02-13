#ifndef MODEL_VISUALIZATION_MESSAGE_OPERATIONSINGLEFUND_HPP
#define MODEL_VISUALIZATION_MESSAGE_OPERATIONSINGLEFUND_HPP

#include <visualization/message/OperationInterface.hpp>

namespace model
{
namespace visualization
{
namespace message
{

class OperationSingleFund:
        public model::visualization::message::OperationInterface
{
    public:
        OperationSingleFund(model::visualization::message::OperationType operationType,
                            int amount,
                            model::operations::FundType fundType);

        std::string toString() override;
};

}
}
}

#endif // MODEL_VISUALIZATION_MESSAGE_OPERATIONSINGLEFUND_HPP
