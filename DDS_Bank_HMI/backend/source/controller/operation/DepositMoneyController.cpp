#include "DepositMoneyController.hpp"

namespace backend
{
namespace  controller
{
namespace  operation
{

DepositMoneyController::DepositMoneyController(std::shared_ptr<model::FundIncreaseAmountInterface> fund) :
    m_fund(fund)
{

}

void DepositMoneyController::deposit(int amount)
{
    m_fund->increaseAmount(amount);
}


}
}
}

