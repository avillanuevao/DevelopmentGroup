#include "SelectFundController.hpp"

namespace backend
{
namespace controller
{
namespace operations
{

SelectFundController::SelectFundController(std::shared_ptr<model::operations::FundSetParameterInterface> fund):
    m_fund(fund)
{

}

void SelectFundController::selectFundType(model::operations::FundType fundType)
{
    m_fund->setFundType(fundType);
}

}
}
}
