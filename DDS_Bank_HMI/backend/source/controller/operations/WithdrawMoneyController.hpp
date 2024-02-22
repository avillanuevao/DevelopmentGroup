#ifndef BACKEND_CONTROLLER_OPERATIONS_WITHDRAWMONEYCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATIONS_WITHDRAWMONEYCONTROLLER_HPP

#include <memory>

#include <model/source/operations/iFundDecreaseAmount.hpp>
#include <model/source/operations/iFundGetParameters.hpp>

#include <utils/source/designPattern/SignalPublisher.hpp>
#include <backend/source/controller/operations/signal/ShowMessageSignal.hpp>


namespace backend
{
namespace controller
{
namespace operations
{

class WithdrawMoneyController:
        public utils::designPattern::SignalPublisher<backend::controller::operations::signal::ShowMessageSignal>
{
    public:
        WithdrawMoneyController(std::shared_ptr<model::operations::iFundDecreaseAmount> fundDecrease,
                                std::shared_ptr<model::operations::iFundGetParameters> fundGetParameter);

        void withdraw(int amount);

    private:
        void sendShowMessageSignal(model::visualization::message::kMessageType messageType, int amount);

        std::shared_ptr<model::operations::iFundDecreaseAmount> m_fundDecrease;
        std::shared_ptr<model::operations::iFundGetParameters> m_fundGetParameter;

};

}
}
}

#endif // BACKEND_CONTROLLER_OPERATIONS_WITHDRAWMONEYCONTROLLER_HPP
