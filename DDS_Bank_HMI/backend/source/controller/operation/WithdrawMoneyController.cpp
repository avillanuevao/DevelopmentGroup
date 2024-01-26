#include <backend/source/controller/operation/WithdrawMoneyController.hpp>

namespace backend
{
namespace controller
{
namespace operation
{

WithdrawMoneyController::WithdrawMoneyController(std::shared_ptr<model::AllFunds> allFunds):
    m_allFunds(allFunds)
{

}

void WithdrawMoneyController::withdraw(model::Operation withdraw)
{
    //TODO: si no hay suficiente dinero saco de SAVINGS, si no hay en SAVINGS no lo hago

    m_allFunds->decreaseAmount(withdraw.getFundTypeDestination(), withdraw.getAmount());
}

}
}
}
