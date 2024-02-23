#ifndef BACKEND_CONTROLLER_OPERATIONS_TRANSFERMONEY_HPP
#define BACKEND_CONTROLLER_OPERATIONS_TRANSFERMONEY_HPP

#include <memory>

#include <backend/source/controller/operations/signal/ShowMessage.hpp>
#include <model/source/operations/iFundGetParameters.hpp>
#include <model/source/operations/iFundTransferAmount.hpp>
#include <utils/source/designPattern/SignalPublisher.hpp>

namespace  backend
{
namespace  controller
{
namespace  operations
{

class TransferMoney :
    public utils::designPattern::SignalPublisher<backend::controller::operations::signal::ShowMessage>
{
  public:
    TransferMoney(std::shared_ptr<model::operations::iFundTransferAmount> fund,
                  std::shared_ptr<model::operations::iFundGetParameters> fundGetParameter);

    void transfer(model::operations::kFundType destinationFundType, int amount);

  private:
    void sendShowMessageSignal(model::visualization::message::kMessageType messageType, int amount,
                               model::operations::kFundType destinationFundType);

    std::shared_ptr<model::operations::iFundTransferAmount> mFund;
    std::shared_ptr<model::operations::iFundGetParameters> mFundGetParameter;
};

}  // namespace operations
}  // namespace controller
}  // namespace backend

#endif  // BACKEND_CONTROLLER_OPERATIONS_TRANSFERMONEY_HPP
