#include "SelectFundController.hpp"

namespace backend
{
namespace controller
{
namespace operations
{

SelectFundController::SelectFundController(std::shared_ptr<model::operations::iFundSetParameter> fund):
    m_fund(fund)
{

}

void SelectFundController::selectFundType(model::operations::kFundType fundType)
{
    m_fund->setFundType(fundType);
}

}
}
}
