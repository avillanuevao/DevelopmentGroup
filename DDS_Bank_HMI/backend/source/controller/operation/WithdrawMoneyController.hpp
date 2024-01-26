#ifndef BACKEND_CONTROLLER_OPERATION_WITHDRAWMONEYCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATION_WITHDRAWMONEYCONTROLLER_HPP

#include <model/source/AllFunds.hpp>
#include <model/source/Operation.hpp>

namespace backend
{
namespace controller
{
namespace operation
{

class WithdrawMoneyController
{
    public:
        WithdrawMoneyController(std::shared_ptr<model::AllFunds> allFunds);
        void withdraw(model::Operation withdraw);

    private:
        std::shared_ptr<model::AllFunds> m_allFunds;

};

}
}
}

#endif // BACKEND_CONTROLLER_OPERATION_WITHDRAWMONEYCONTROLLER_HPP
