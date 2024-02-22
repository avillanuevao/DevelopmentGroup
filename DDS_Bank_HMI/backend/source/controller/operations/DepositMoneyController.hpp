#ifndef BACKEND_CONTROLLER_OPERATIONS_DEPOSITMONEYCONTROLLER_HPP
#define BACKEND_CONTROLLER_OPERATIONS_DEPOSITMONEYCONTROLLER_HPP

#include <iostream>
#include <memory>
#include <limits>

#include <model/source/operations/iFundIncreaseAmount.hpp>
#include <model/source/operations/iFundGetParameters.hpp>

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
        DepositMoneyController(std::shared_ptr<model::operations::iFundIncreaseAmount> fundIncreaseAmount,
                               std::shared_ptr<model::operations::iFundGetParameters> fundGetParameter);

        void deposit(int amount);

    private:
        void sendShowMessageSignal(model::visualization::message::kMessageType messageType, int amount);

        std::shared_ptr<model::operations::iFundIncreaseAmount> m_fundIncreaseAmount;
        std::shared_ptr<model::operations::iFundGetParameters> m_fundGetParameter;
};

}
}
}
#endif // BACKEND_CONTROLLER_OPERATIONS_DEPOSITMONEYCONTROLLER_HPP
