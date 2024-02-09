#ifndef BACKEND_CONTROLLER_OPERATIONS_DEPOSITMONEYCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATIONS_DEPOSITMONEYCONTROLLER_HPP

#include <iostream>
#include <memory>
#include <limits>

#include <model/source/operations/FundIncreaseAmountInterface.hpp>

namespace backend
{
namespace controller
{
namespace operations
{

class DepositMoneyController
{
    public:
        DepositMoneyController(std::shared_ptr<model::operations::FundIncreaseAmountInterface> fund);

        void deposit(int amount);

    private:
        std::shared_ptr<model::operations::FundIncreaseAmountInterface> m_fund;
};

}
}
}
#endif // BACKEND_CONTROLLER_OPERATIONS_DEPOSITMONEYCONTROLLER_HPP
