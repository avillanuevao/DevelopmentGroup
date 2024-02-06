#include "SelectFundController.hpp"

namespace backend
{
namespace controller
{
namespace operation
{

SelectFundController::SelectFundController(std::shared_ptr<model::FundSetParameterInterface> fund):
    m_fund(fund)
{

}

void SelectFundController::selectFundType(model::FundType fundType)
{
    m_fund->setFundType(fundType);
}

}
}
}
