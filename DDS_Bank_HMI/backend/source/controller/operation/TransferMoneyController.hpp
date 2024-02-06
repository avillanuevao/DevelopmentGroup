#ifndef BACKEND_CONTROLLER_OPERATION_TRANSFERMONEYCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATION_TRANSFERMONEYCONTROLLER_HPP

#include <memory>

#include <model/source/FundTransferAmountInterface.hpp>

namespace  backend
{
namespace  controller
{
namespace  operation
{


class TransferMoneyController
{
    public:
        TransferMoneyController(std::shared_ptr<model::FundTransferAmountInterface> fund);

        void transfer(model::FundType destinationFundType, int amount);

    private:
        std::shared_ptr<model::FundTransferAmountInterface> m_fund;
};

}
}
}

#endif // BACKEND_CONTROLLER_OPERATION_TRANSFERMONEYCONTROLLER_HPP
