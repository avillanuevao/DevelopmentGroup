#include "UpdatedFundTypeSignal.hpp"

namespace model
{
namespace operations
{
namespace signal
{

UpdatedFundTypeSignal::UpdatedFundTypeSignal(model::operations::FundType fundType)
    : m_fundType(fundType)
{
}

model::operations::FundType UpdatedFundTypeSignal::getFundType() const
{
    return m_fundType;
}

void UpdatedFundTypeSignal::setFundType(model::operations::FundType newFundType)
{
    m_fundType = newFundType;
}

}
}
}
