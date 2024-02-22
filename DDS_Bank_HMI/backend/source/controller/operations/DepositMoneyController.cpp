#include "DepositMoneyController.hpp"

namespace backend
{
namespace  controller
{
namespace  operations
{

DepositMoneyController::DepositMoneyController(std::shared_ptr<model::operations::iFundIncreaseAmount> fundIncreaseAmount,
                                               std::shared_ptr<model::operations::iFundGetParameters> fundGetParameter) :
    m_fundIncreaseAmount(fundIncreaseAmount),
    m_fundGetParameter(fundGetParameter)
{

}

void DepositMoneyController::deposit(int amount)
{
    try
    {

        m_fundIncreaseAmount->increaseAmount(amount);

        sendShowMessageSignal(model::visualization::message::kMessageType::Success, amount);
    }
    catch (std::logic_error e)
    {
        sendShowMessageSignal(model::visualization::message::kMessageType::Failure, amount);

        std::cerr << e.what() << std::endl;
    }
}

void DepositMoneyController::sendShowMessageSignal(model::visualization::message::kMessageType messageType, int amount)
{
    std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    backend::controller::operations::signal::ShowMessageSignal signal(date,
                                                                      messageType,
                                                                      model::visualization::message::kOperationType::Deposit,
                                                                      amount,
                                                                      m_fundGetParameter->getFundType());
    notifySubscribers(signal);
}

}
}
}

