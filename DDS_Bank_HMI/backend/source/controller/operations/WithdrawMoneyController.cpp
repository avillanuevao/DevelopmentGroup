#include <backend/source/controller/operations/WithdrawMoneyController.hpp>

namespace backend
{
namespace controller
{
namespace operations
{

WithdrawMoneyController::WithdrawMoneyController(std::shared_ptr<model::operations::FundDecreaseAmountInterface> fundDecrease):
    m_fundDecrease(fundDecrease)
{

}

void WithdrawMoneyController::withdraw(int amount)
{
    m_fundDecrease->decreaseAmount(amount);
}

}
}
}
