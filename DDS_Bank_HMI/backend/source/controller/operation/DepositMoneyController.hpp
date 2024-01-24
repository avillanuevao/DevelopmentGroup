#ifndef DEPOSITMONEYCONTROLLER_HPP
#define DEPOSITMONEYCONTROLLER_HPP

#include <model/source/AllFunds.hpp>
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
        DepositMoneyController(std::shared_ptr<model::AllFunds> allFunds);
        void doDeposit(model::Operation deposit);
    private:
        std::shared_ptr<model::AllFunds> m_allFunds;


};

}
}
}
#endif // DEPOSITMONEYCONTROLLER_HPP
