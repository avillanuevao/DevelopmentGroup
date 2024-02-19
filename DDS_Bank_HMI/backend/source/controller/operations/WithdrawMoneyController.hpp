#ifndef BACKEND_CONTROLLER_OPERATIONS_WITHDRAWMONEYCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATIONS_WITHDRAWMONEYCONTROLLER_HPP

#include <memory>

#include <model/source/operations/FundDecreaseAmountInterface.hpp>
#include <model/source/operations/FundGetParametersInterface.hpp>

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
        WithdrawMoneyController(std::shared_ptr<model::operations::FundDecreaseAmountInterface> fundDecrease,
                                std::shared_ptr<model::operations::FundGetParametersInterface> fundGetParameter);

        void withdraw(int amount);

    private:
        void sendShowMessageSignal(model::visualization::message::MessageType messageType, int amount);

        std::shared_ptr<model::operations::FundDecreaseAmountInterface> m_fundDecrease;
        std::shared_ptr<model::operations::FundGetParametersInterface> m_fundGetParameter;

};

}
}
}

#endif // BACKEND_CONTROLLER_OPERATIONS_WITHDRAWMONEYCONTROLLER_HPP
