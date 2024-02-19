#include "TransferMoneyController.hpp"

namespace  backend
{
namespace  controller
{
namespace  operations
{

TransferMoneyController::TransferMoneyController(std::shared_ptr<model::operations::FundTransferAmountInterface> fund,
                                                 std::shared_ptr<model::operations::FundGetParametersInterface> fundGetParameter):
    m_fund(fund),
    m_fundGetParameter(fundGetParameter)
{

}

void TransferMoneyController::transfer(model::operations::FundType destinationFundType, int amount)
{
    try
    {
        m_fund->transferAmount(destinationFundType, amount);

        sendShowMessageSignal(model::visualization::message::MessageType::SUCCESS, amount, destinationFundType);
    }
    catch (std::logic_error e) {
        std::cerr << e.what() << std::endl;

        sendShowMessageSignal(model::visualization::message::MessageType::FAILURE, amount, destinationFundType);
    }
}

void TransferMoneyController::sendShowMessageSignal(model::visualization::message::MessageType messageType, int amount, model::operations::FundType destinationFundType)
{
    std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    backend::controller::operations::signal::ShowMessageSignal signal(date,
                                                                      messageType,
                                                                      model::visualization::message::OperationType::TRANSFER,
                                                                      amount,
                                                                      m_fundGetParameter->getFundType(),
                                                                      destinationFundType);
    notifySubscribers(signal);
}

}
}
}
