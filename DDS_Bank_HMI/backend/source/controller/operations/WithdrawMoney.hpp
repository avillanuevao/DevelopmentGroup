#ifndef BACKEND_CONTROLLER_OPERATIONS_WITHDRAWMONEY_HPP
#define BACKEND_CONTROLLER_OPERATIONS_WITHDRAWMONEY_HPP

#include <memory>

#include <backend/source/controller/operations/signal/ShowMessage.hpp>
#include <model/source/operations/iFundDecreaseAmount.hpp>
#include <model/source/operations/iFundGetParameters.hpp>
#include <utils/source/designPattern/SignalPublisher.hpp>

namespace backend
{
namespace controller
{
namespace operations
{

class WithdrawMoney :
    public utils::designPattern::SignalPublisher<backend::controller::operations::signal::ShowMessage>
{
  public:
    WithdrawMoney(std::shared_ptr<model::operations::iFundDecreaseAmount> fundDecrease,
                  std::shared_ptr<model::operations::iFundGetParameters> fundGetParameter);

    void withdraw(int amount);

  private:
    void sendShowMessageSignal(model::visualization::message::kMessageType messageType, int amount);

    std::shared_ptr<model::operations::iFundDecreaseAmount> mFundDecrease;
    std::shared_ptr<model::operations::iFundGetParameters> mFundGetParameter;
};

}  // namespace operations
}  // namespace controller
}  // namespace backend

#endif // BACKEND_CONTROLLER_OPERATIONS_WITHDRAWMONEY_HPP
