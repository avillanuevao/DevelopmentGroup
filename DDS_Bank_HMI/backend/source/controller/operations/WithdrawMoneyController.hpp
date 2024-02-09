#ifndef BACKEND_CONTROLLER_OPERATIONS_WITHDRAWMONEYCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATIONS_WITHDRAWMONEYCONTROLLER_HPP

#include <memory>

#include <model/source/operations/FundDecreaseAmountInterface.hpp>
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
        WithdrawMoneyController(std::shared_ptr<model::operations::FundDecreaseAmountInterface> fundDecrease);

        void withdraw(int amount);

    private:
        std::shared_ptr<model::operations::FundDecreaseAmountInterface> m_fundDecrease;

};

}
}
}

#endif // BACKEND_CONTROLLER_OPERATIONS_WITHDRAWMONEYCONTROLLER_HPP
