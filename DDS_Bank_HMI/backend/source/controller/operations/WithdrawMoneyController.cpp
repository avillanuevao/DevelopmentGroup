#include <backend/source/controller/operations/WithdrawMoneyController.hpp>

namespace backend
{
namespace controller
{
namespace operations
{

WithdrawMoneyController::WithdrawMoneyController(std::shared_ptr<model::operations::FundDecreaseAmountInterface> fundDecrease,
                                                 std::shared_ptr<model::operations::FundDecreaseAmountByFundTypeInterface> fundDecreaseByFundType,
                                                 std::shared_ptr<model::operations::FundGetParametersInterface> fundGetAmount,
                                                 std::shared_ptr<model::operations::FundGetAmountByFundTypeInterface> fundGetAmountByFundType):
    m_fundDecrease(fundDecrease),
    m_fundDecreaseByFundType(fundDecreaseByFundType),
    m_fundGetAmount(fundGetAmount),
    m_fundGetAmountByFundType(fundGetAmountByFundType)
{

}

void WithdrawMoneyController::withdraw(int amount)
{
    int amountFund = m_fundGetAmount->getAmount();
    int amountSavings = m_fundGetAmountByFundType->getAmount(model::operations::FundType::SAVINGS);

    if((amountFund - amount) >= 0)
    {
        m_fundDecrease->decreaseAmount(amount);
    }
    else if ((amountSavings - amount) > 0)
    {
        m_fundDecreaseByFundType->decreaseAmount(model::operations::FundType::SAVINGS, amount);
    }
    else
    {
        throw std::logic_error("Amount in SAVINGS fund not enough");
    }
}

}
}
}
