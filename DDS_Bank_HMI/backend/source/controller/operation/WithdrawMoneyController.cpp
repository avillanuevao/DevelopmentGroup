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
    int amountFund = m_allFunds->getAmount(withdraw.getFundTypeDestination());
    int amountSavings = m_allFunds->getAmount(model::FundType::SAVINGS);
    int withdrawn = withdraw.getAmount();

    if((amountFund - withdrawn) > 0)
    {
        m_allFunds->decreaseAmount(withdraw.getFundTypeDestination(), withdraw.getAmount());
    }
    else if ((amountSavings - withdrawn) > 0)
    {
        m_allFunds->decreaseAmount(model::FundType::SAVINGS, withdraw.getAmount());
    }
    else
    {
        throw std::logic_error("Amount in SAVINGS fund not enough");
    }
}

}
}
}
