#include <backend/source/controller/operation/WithdrawMoneyController.hpp>

namespace backend
{
namespace controller
{
namespace operation
{

WithdrawMoneyController::WithdrawMoneyController(std::shared_ptr<model::FundDecreaseAmountInterface> fundDecrease, std::shared_ptr<model::FundDecreaseAmountByFundTypeInterface> fundDecreaseByFundType,
                                                 std::shared_ptr<model::FundGetAmountInterface> fundGetAmount,
                                                 std::shared_ptr<model::FundGetAmountByFundTypeInterface> fundGetAmountByFundType):
    m_fundDecrease(fundDecrease),
    m_fundDecreaseByFundType(fundDecreaseByFundType),
    m_fundGetAmount(fundGetAmount),
    m_fundGetAmountByFundType(fundGetAmountByFundType)
{

}

void WithdrawMoneyController::withdraw(int amount)
{

    //TODO: si no hay suficiente dinero saco de SAVINGS, si no hay en SAVINGS no lo hago
    int amountFund = m_fundGetAmount->getAmount();
    int amountSavings = m_fundGetAmountByFundType->getAmount(model::FundType::SAVINGS);

    if((amountFund - amount) >= 0)
    {
        m_fundDecrease->decreaseAmount(amount);
    }
    else if ((amountSavings - amount) > 0)
    {
        m_fundDecreaseByFundType->decreaseAmount(model::FundType::SAVINGS, amount);
    }
    else
    {
        throw std::logic_error("Amount in SAVINGS fund not enough");
    }
}

}
}
}
