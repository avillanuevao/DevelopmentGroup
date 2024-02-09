#ifndef BACKEND_CONTROLLER_OPERATIONS_TRANSFERMONEYCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATIONS_TRANSFERMONEYCONTROLLER_HPP

#include <memory>

#include <model/source/operations/FundTransferAmountInterface.hpp>

namespace  backend
{
namespace  controller
{
namespace  operations
{


class TransferMoneyController
{
    public:
        TransferMoneyController(std::shared_ptr<model::operations::FundTransferAmountInterface> fund);

        void transfer(model::operations::FundType destinationFundType, int amount);

    private:
        std::shared_ptr<model::operations::FundTransferAmountInterface> m_fund;
};

}
}
}

#endif // BACKEND_CONTROLLER_OPERATIONS_TRANSFERMONEYCONTROLLER_HPP
