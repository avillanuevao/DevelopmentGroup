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

SelectFundSignal::SelectFundSignal(model::operations::kFundType fundType) :
    m_fundType(fundType)
{

}

model::operations::kFundType SelectFundSignal::getFundType() const
{
    return m_fundType;
}

void SelectFundSignal::setFundType(model::operations::kFundType newFundType)
{
    m_fundType = newFundType;
}

}
}
}
}
}
