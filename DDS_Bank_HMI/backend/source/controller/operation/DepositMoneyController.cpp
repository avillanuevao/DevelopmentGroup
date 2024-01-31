#include "DepositMoneyController.hpp"

namespace backend
{
namespace  controller
{
namespace  operation
{

DepositMoneyController::DepositMoneyController(std::shared_ptr<model::FundInterface> fund) :
    m_fund(fund)
{

}

void DepositMoneyController::doDeposit(model::Operation deposit)
{
    m_fund->increaseAmount(deposit.getAmount());
}


}
}
}

