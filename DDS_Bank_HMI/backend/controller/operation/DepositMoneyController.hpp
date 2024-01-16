#ifndef DEPOSITMONEYCONTROLLER_HPP
#define DEPOSITMONEYCONTROLLER_HPP

#include <idl/bank.hpp>
#include <model/AllFunds.hpp>

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
        void doDeposit(Deposit deposit);
    private:
        std::shared_ptr<model::AllFunds> m_allFunds;


};

}
}
}
#endif // DEPOSITMONEYCONTROLLER_HPP
