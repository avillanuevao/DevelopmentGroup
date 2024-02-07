#ifndef BACKEND_CONTROLLER_OPERATION_WITHDRAWMONEYCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATION_WITHDRAWMONEYCONTROLLER_HPP

#include <memory>

#include <model/source/operations/FundDecreaseAmountInterface.hpp>
#include <model/source/operations/FundDecreaseAmountByFundTypeInterface.hpp>
#include <model/source/operations/FundGetParametersInterface.hpp>
#include <model/source/operations/FundGetAmountByFundTypeInterface.hpp>


namespace backend
{
namespace controller
{
namespace operations
{

class WithdrawMoneyController
{
    public:
        WithdrawMoneyController(std::shared_ptr<model::operations::FundDecreaseAmountInterface> fundDecrease,
                                std::shared_ptr<model::operations::FundDecreaseAmountByFundTypeInterface> fundDecreaseByFundType,
                                std::shared_ptr<model::operations::FundGetParametersInterface> fundGetAmount,
                                std::shared_ptr<model::operations::FundGetAmountByFundTypeInterface> fundGetAmountByFundType);

        void withdraw(int amount);

    private:
        std::shared_ptr<model::operations::FundDecreaseAmountInterface> m_fundDecrease;
        std::shared_ptr<model::operations::FundDecreaseAmountByFundTypeInterface> m_fundDecreaseByFundType;
        std::shared_ptr<model::operations::FundGetParametersInterface> m_fundGetAmount;
        std::shared_ptr<model::operations::FundGetAmountByFundTypeInterface> m_fundGetAmountByFundType;

};

}
}
}

#endif // BACKEND_CONTROLLER_OPERATION_WITHDRAWMONEYCONTROLLER_HPP
