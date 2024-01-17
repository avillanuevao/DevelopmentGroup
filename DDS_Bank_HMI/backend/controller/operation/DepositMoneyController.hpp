#ifndef DEPOSITMONEYCONTROLLER_HPP
#define DEPOSITMONEYCONTROLLER_HPP

#include <model/AllFunds.hpp>
#include <model/Deposit.hpp>

namespace backend
{
namespace controller
{
namespace operation
{

class DepositMoneyController
{
    public:
        DepositMoneyController(std::shared_ptr<model::AllFunds> allFunds);
        void doDeposit(model::Deposit deposit);
    private:
        std::shared_ptr<model::AllFunds> m_allFunds;


};

}
}
}
#endif // DEPOSITMONEYCONTROLLER_HPP
