#ifndef BACKEND_CONTROLLER_OPERATIONS_DEPOSITMONEY_HPP
#define BACKEND_CONTROLLER_OPERATIONS_DEPOSITMONEY_HPP

#include <iostream>
#include <memory>

#include <backend/source/controller/operations/signal/SaveFund.hpp>
#include <backend/source/controller/operations/signal/ShowMessage.hpp>
#include <model/source/operations/iFundGetParameters.hpp>
#include <model/source/operations/iFundIncreaseAmount.hpp>
#include <utils/source/designPattern/SignalPublisher.hpp>

namespace backend
{
namespace controller
{
namespace operations
{

class DepositMoney :
    public utils::designPattern::SignalPublisher<backend::controller::operations::signal::ShowMessage>,
    public utils::designPattern::SignalPublisher<backend::controller::operations::signal::SaveFund>
{
  public:
    DepositMoney(std::shared_ptr<model::operations::iFundIncreaseAmount> fundIncreaseAmount,
                 std::shared_ptr<model::operations::iFundGetParameters> fundGetParameter);

    void deposit(int amount);

  private:
    void sendShowMessageSignal(model::visualization::message::kMessageType messageType, int amount);
    void sendSaveFundSignal(model::operations::kFundType fundChanged);

    std::shared_ptr<model::operations::iFundIncreaseAmount> mFundIncreaseAmount;
    std::shared_ptr<model::operations::iFundGetParameters> mFundGetParameter;
};

}  // namespace operations
}  // namespace controller
}  // namespace backend

#endif  // BACKEND_CONTROLLER_OPERATIONS_DEPOSITMONEY_HPP
