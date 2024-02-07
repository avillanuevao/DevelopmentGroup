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

SelectFundSignal::SelectFundSignal(model::operations::FundType fundType) :
    m_fundType(fundType)
{

}

model::operations::FundType SelectFundSignal::getFundType() const
{
    return m_fundType;
}

void SelectFundSignal::setFundType(model::operations::FundType newFundType)
{
    m_fundType = newFundType;
}

}
}
}
}
}
