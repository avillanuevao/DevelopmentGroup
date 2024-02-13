#ifndef MODEL_VISUALIZATION_OPERATIONDUALFUND_HPP
#define MODEL_VISUALIZATION_OPERATIONDUALFUND_HPP

#include <visualization/message/OperationInterface.hpp>

namespace model
{
namespace visualization
{
namespace message
{

class OperationDualFund:
        public model::visualization::message::OperationInterface
{
    public:
        OperationDualFund(model::visualization::message::OperationType operationType,
                          int amount,
                          model::operations::FundType originFund,
                          model::operations::FundType destinationFund);

        std::string toString() override;

    private:
        model::operations::FundType m_destinationFund;
};

}
}
}

#endif // MODEL_VISUALIZATION_OPERATIONDUALFUND_HPP
