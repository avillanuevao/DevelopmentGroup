#ifndef BACKEND_CONTROLLER_OPERATIONS_TRANSFERMONEYCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATIONS_TRANSFERMONEYCONTROLLER_HPP

#include <memory>

#include <model/source/operations/FundTransferAmountInterface.hpp>
#include <model/source/operations/FundGetParametersInterface.hpp>

#include <utils/source/designPattern/SignalPublisher.hpp>
#include <backend/source/controller/operations/signal/ShowMessageSignal.hpp>

namespace  backend
{
namespace  controller
{
namespace  operations
{


class TransferMoneyController:
        public utils::designPattern::SignalPublisher<backend::controller::operations::signal::ShowMessageSignal>
{
    public:
        TransferMoneyController(std::shared_ptr<model::operations::FundTransferAmountInterface> fund,
                                std::shared_ptr<model::operations::FundGetParametersInterface> fundGetParameter);

        void transfer(model::operations::FundType destinationFundType, int amount);

    private:
        void sendShowMessageSignal(model::visualization::message::MessageType messageType, int amount, model::operations::FundType destinationFundType);

        std::shared_ptr<model::operations::FundTransferAmountInterface> m_fund;
        std::shared_ptr<model::operations::FundGetParametersInterface> m_fundGetParameter;
};

}
}
}

#endif // BACKEND_CONTROLLER_OPERATIONS_TRANSFERMONEYCONTROLLER_HPP
