#ifndef BACKEND_CONTROLLER_OPERATION_TRANSFERMONEYCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATION_TRANSFERMONEYCONTROLLER_HPP

#include <memory>

#include <model/source/AllFunds.hpp>
#include <model/source/Operation.hpp>

namespace  backend
{
namespace  controller
{
namespace  operation
{


class TransferMoneyController
{
    public:
        TransferMoneyController(std::shared_ptr<model::AllFunds> allFunds);

        void doTransaction(model::Operation transaction);

    private:
        std::shared_ptr<model::AllFunds> m_allFunds;
};

}
}
}

#endif // BACKEND_CONTROLLER_OPERATION_TRANSFERMONEYCONTROLLER_HPP
