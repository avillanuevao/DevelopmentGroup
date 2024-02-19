#include "DepositMoneyController.hpp"

namespace backend
{
namespace  controller
{
namespace  operations
{

DepositMoneyController::DepositMoneyController(std::shared_ptr<model::operations::FundIncreaseAmountInterface> fundIncreaseAmount,
                                               std::shared_ptr<model::operations::FundGetParametersInterface> fundGetParameter) :
    m_fundIncreaseAmount(fundIncreaseAmount),
    m_fundGetParameter(fundGetParameter)
{

}

void DepositMoneyController::deposit(int amount)
{
    try
    {

        m_fundIncreaseAmount->increaseAmount(amount);

        sendShowMessageSignal(model::visualization::message::MessageType::SUCCESS, amount);
    }
    catch (std::logic_error e)
    {
        sendShowMessageSignal(model::visualization::message::MessageType::FAILURE, amount);

        std::cerr << e.what() << std::endl;
    }
}

void DepositMoneyController::sendShowMessageSignal(model::visualization::message::MessageType messageType, int amount)
{
    std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    backend::controller::operations::signal::ShowMessageSignal signal(date,
                                                                      messageType,
                                                                      model::visualization::message::OperationType::DEPOSIT,
                                                                      amount,
                                                                      m_fundGetParameter->getFundType());
    notifySubscribers(signal);
}

}
}
}

