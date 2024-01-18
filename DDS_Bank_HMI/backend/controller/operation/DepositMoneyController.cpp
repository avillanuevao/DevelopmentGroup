#include "DepositMoneyController.hpp"

namespace backend
{
namespace  controller
{
namespace  operation
{

DepositMoneyController::DepositMoneyController(std::shared_ptr<model::AllFunds> allFunds) :
    m_allFunds(allFunds)
{

}

void DepositMoneyController::doDeposit(model::Operation deposit)
{
    m_allFunds->increaseAmount(deposit.getFundTypeDestination(), deposit.getAmount());
}


}
}
}

