#include "UpdatedFundTypeSignal.hpp"

namespace model
{
namespace signal
{

UpdatedFundTypeSignal::UpdatedFundTypeSignal(model::FundType fundType)
    : m_fundType(fundType)
{
}

model::FundType UpdatedFundTypeSignal::getFundType() const
{
    return m_fundType;
}

void UpdatedFundTypeSignal::setFundType(model::FundType newFundType)
{
    m_fundType = newFundType;
}

}
}
