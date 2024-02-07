#ifndef MODEL_OPERATIONS_SIGNAL_UPDATEDFUNDTYPESIGNAL_HPP
#define MODEL_OPERATIONS_SIGNAL_UPDATEDFUNDTYPESIGNAL_HPP


#include <operations/FundType.hpp>

namespace  model
{
namespace operations
{
namespace signal
{

class UpdatedFundTypeSignal
{
    public:
        UpdatedFundTypeSignal(model::operations::FundType fundType);

        model::operations::FundType getFundType() const;
        void setFundType(model::operations::FundType newFundType);

private:
        model::operations::FundType m_fundType;
};

}
}
}
#endif // MODEL_OPERATIONS_SIGNAL_UPDATEDFUNDTYPESIGNAL_HPP
