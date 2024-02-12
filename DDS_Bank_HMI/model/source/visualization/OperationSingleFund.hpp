#ifndef MODEL_VISUALIZATION_OPERATIONSINGLEFUND_HPP
#define MODEL_VISUALIZATION_OPERATIONSINGLEFUND_HPP

#include <visualization/OperationInterface.hpp>

namespace model
{
namespace visualization
{

class OperationSingleFund:
        public model::visualization::OperationInterface
{
    public:
        OperationSingleFund(model::visualization::OperationType operationType,
                            int amount,
                            model::operations::FundType fundType);

        std::string toString() override;
};

}
}

#endif // MODEL_VISUALIZATION_OPERATIONSINGLEFUND_HPP
