#include "SelectFundSignal.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{
namespace signal
{

SelectFundSignal::SelectFundSignal(model::FundType fundType) :
    m_fundType(fundType)
{

}

model::FundType SelectFundSignal::getFundType() const
{
    return m_fundType;
}

void SelectFundSignal::setFundType(model::FundType newFundType)
{
    m_fundType = newFundType;
}

}
}
}
}
}
