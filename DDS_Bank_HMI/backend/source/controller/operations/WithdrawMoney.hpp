#ifndef BACKEND_CONTROLLER_OPERATIONS_WITHDRAWMONEY_HPP
#define BACKEND_CONTROLLER_OPERATIONS_WITHDRAWMONEY_HPP

#include <memory>

#include <backend/source/controller/operations/signal/SaveFund.hpp>
#include <backend/source/controller/operations/signal/ShowMessage.hpp>
#include <model/source/operations/iFundDecreaseAmount.hpp>
#include <model/source/operations/iFundGetParameters.hpp>
#include <model/source/operations/kFundType.hpp>
#include <utils/source/designPattern/SignalPublisher.hpp>

namespace backend
{
namespace controller
{
namespace operations
{

class WithdrawMoney :
    public utils::designPattern::SignalPublisher<backend::controller::operations::signal::ShowMessage>,
    public utils::designPattern::SignalPublisher<backend::controller::operations::signal::SaveFund>
{
  public:
    WithdrawMoney(std::shared_ptr<model::operations::iFundDecreaseAmount> fundDecreaseAmount,
                  std::shared_ptr<model::operations::iFundGetParameters> fundGetParameter);

    void withdraw(int amount);

  private:
    void sendShowMessageSignal(model::visualization::message::kMessageType messageType, int amount);
    void sendSaveFundSignal(model::operations::kFundType fundChanged);

    std::shared_ptr<model::operations::iFundDecreaseAmount> mFundDecreaseAmount;
    std::shared_ptr<model::operations::iFundGetParameters> mFundGetParameters;
};

}  // namespace operations
}  // namespace controller
}  // namespace backend

#endif  // BACKEND_CONTROLLER_OPERATIONS_WITHDRAWMONEY_HPP
