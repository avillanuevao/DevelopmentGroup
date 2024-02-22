#include "TransferMoneyController.hpp"

namespace  backend
{
namespace  controller
{
namespace  operations
{

TransferMoneyController::TransferMoneyController(std::shared_ptr<model::operations::iFundTransferAmount> fund,
                                                 std::shared_ptr<model::operations::iFundGetParameters> fundGetParameter):
    m_fund(fund),
    m_fundGetParameter(fundGetParameter)
{

}

void TransferMoneyController::transfer(model::operations::kFundType destinationFundType, int amount)
{
    try
    {
        m_fund->transferAmount(destinationFundType, amount);

        sendShowMessageSignal(model::visualization::message::kMessageType::Success, amount, destinationFundType);
    }
    catch (std::logic_error e) {
        std::cerr << e.what() << std::endl;

        sendShowMessageSignal(model::visualization::message::kMessageType::Failure, amount, destinationFundType);
    }
}

void TransferMoneyController::sendShowMessageSignal(model::visualization::message::kMessageType messageType, int amount, model::operations::kFundType destinationFundType)
{
    std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    backend::controller::operations::signal::ShowMessageSignal signal(date,
                                                                      messageType,
                                                                      model::visualization::message::kOperationType::Transfer,
                                                                      amount,
                                                                      m_fundGetParameter->getFundType(),
                                                                      destinationFundType);
    notifySubscribers(signal);
}

}
}
}
