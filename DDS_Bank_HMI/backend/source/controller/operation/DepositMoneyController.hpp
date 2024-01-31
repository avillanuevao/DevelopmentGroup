#ifndef DEPOSITMONEYCONTROLLER_HPP
#define DEPOSITMONEYCONTROLLER_HPP

#include <memory>

#include <model/source/FundInterface.hpp>
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
        DepositMoneyController(std::shared_ptr<model::FundInterface> fund);
        void doDeposit(model::Operation deposit);
    private:
        std::shared_ptr<model::FundInterface> m_fund;


};

}
}
}
#endif // DEPOSITMONEYCONTROLLER_HPP
