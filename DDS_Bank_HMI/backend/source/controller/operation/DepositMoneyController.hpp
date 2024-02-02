#ifndef BACKEND_CONTROLLER_OPERATION_DEPOSITMONEYCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATION_DEPOSITMONEYCONTROLLER_HPP

#include <memory>

#include <model/source/FundIncreaseAmountInterface.hpp>
#include <model/source/Operation.hpp>

namespace backend
{
namespace controller
{
namespace operation
{

class DepositMoneyController
{
    public:
        DepositMoneyController(std::shared_ptr<model::FundIncreaseAmountInterface> fund);

        void deposit(int amount);

    private:
        std::shared_ptr<model::FundIncreaseAmountInterface> m_fund;
};

}
}
}
#endif // BACKEND_CONTROLLER_OPERATION_DEPOSITMONEYCONTROLLER_HPP
