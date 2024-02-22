#ifndef BACKEND_CONTROLLER_OPERATIONS_TRANSFERMONEYCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATIONS_TRANSFERMONEYCONTROLLER_HPP

#include <memory>

#include <model/source/operations/iFundTransferAmount.hpp>
#include <model/source/operations/iFundGetParameters.hpp>

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
        TransferMoneyController(std::shared_ptr<model::operations::iFundTransferAmount> fund,
                                std::shared_ptr<model::operations::iFundGetParameters> fundGetParameter);

        void transfer(model::operations::kFundType destinationFundType, int amount);

    private:
        void sendShowMessageSignal(model::visualization::message::kMessageType messageType, int amount, model::operations::kFundType destinationFundType);

        std::shared_ptr<model::operations::iFundTransferAmount> m_fund;
        std::shared_ptr<model::operations::iFundGetParameters> m_fundGetParameter;
};

}
}
}

#endif // BACKEND_CONTROLLER_OPERATIONS_TRANSFERMONEYCONTROLLER_HPP
