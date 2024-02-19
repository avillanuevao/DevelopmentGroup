#ifndef BACKEND_CONTROLLER_OPERATIONS_DEPOSITMONEYCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATIONS_DEPOSITMONEYCONTROLLER_HPP

#include <iostream>
#include <memory>
#include <limits>

#include <model/source/operations/FundIncreaseAmountInterface.hpp>
#include <model/source/operations/FundGetParametersInterface.hpp>

#include <utils/source/designPattern/SignalPublisher.hpp>
#include <backend/source/controller/operations/signal/ShowMessageSignal.hpp>

namespace backend
{
namespace controller
{
namespace operations
{

class DepositMoneyController :
        public utils::designPattern::SignalPublisher<backend::controller::operations::signal::ShowMessageSignal>
{
    public:
        DepositMoneyController(std::shared_ptr<model::operations::FundIncreaseAmountInterface> fundIncreaseAmount,
                               std::shared_ptr<model::operations::FundGetParametersInterface> fundGetParameter);

        void deposit(int amount);

    private:
        void sendShowMessageSignal(model::visualization::message::MessageType messageType, int amount);

        std::shared_ptr<model::operations::FundIncreaseAmountInterface> m_fundIncreaseAmount;
        std::shared_ptr<model::operations::FundGetParametersInterface> m_fundGetParameter;
};

}
}
}
#endif // BACKEND_CONTROLLER_OPERATIONS_DEPOSITMONEYCONTROLLER_HPP
