#include <backend/source/controller/operations/WithdrawMoneyController.hpp>

namespace backend
{
namespace controller
{
namespace operations
{

WithdrawMoneyController::WithdrawMoneyController(std::shared_ptr<model::operations::FundDecreaseAmountInterface> fundDecrease,
                                                 std::shared_ptr<model::operations::FundGetParametersInterface> fundGetParameter):
    m_fundDecrease(fundDecrease),
    m_fundGetParameter(fundGetParameter)
{

}

void WithdrawMoneyController::withdraw(int amount)
{
    try
    {
        m_fundDecrease->decreaseAmount(amount);

        sendShowMessageSignal(model::visualization::message::MessageType::SUCCESS, amount);
    }
    catch (std::logic_error e)
    {
        sendShowMessageSignal(model::visualization::message::MessageType::FAILURE, amount);

        std::cerr << e.what() << std::endl;
    }
}

void WithdrawMoneyController::sendShowMessageSignal(model::visualization::message::MessageType messageType, int amount)
{
    std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    backend::controller::operations::signal::ShowMessageSignal signal(date,
                                                                      messageType,
                                                                      model::visualization::message::OperationType::WITHDRAW,
                                                                      amount,
                                                                      m_fundGetParameter->getFundType());
    notifySubscribers(signal);
}

}
}
}
