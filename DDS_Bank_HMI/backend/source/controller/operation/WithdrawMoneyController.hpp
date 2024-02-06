#ifndef BACKEND_CONTROLLER_OPERATION_WITHDRAWMONEYCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATION_WITHDRAWMONEYCONTROLLER_HPP

#include <memory>

#include <model/source/FundDecreaseAmountInterface.hpp>
#include <model/source/FundDecreaseAmountByFundTypeInterface.hpp>
#include <model/source/FundGetAmountInterface.hpp>
#include <model/source/FundGetAmountByFundTypeInterface.hpp>


namespace backend
{
namespace controller
{
namespace operation
{

class WithdrawMoneyController
{
    public:
        WithdrawMoneyController(std::shared_ptr<model::FundDecreaseAmountInterface> fundDecrease,
                                std::shared_ptr<model::FundDecreaseAmountByFundTypeInterface> fundDecreaseByFundType,
                                std::shared_ptr<model::FundGetAmountInterface> fundGetAmount,
                                std::shared_ptr<model::FundGetAmountByFundTypeInterface> fundGetAmountByFundType);
        void withdraw(int amount);

    private:
        std::shared_ptr<model::FundDecreaseAmountInterface> m_fundDecrease;
        std::shared_ptr<model::FundDecreaseAmountByFundTypeInterface> m_fundDecreaseByFundType;
        std::shared_ptr<model::FundGetAmountInterface> m_fundGetAmount;
        std::shared_ptr<model::FundGetAmountByFundTypeInterface> m_fundGetAmountByFundType;

};

}
}
}

#endif // BACKEND_CONTROLLER_OPERATION_WITHDRAWMONEYCONTROLLER_HPP
