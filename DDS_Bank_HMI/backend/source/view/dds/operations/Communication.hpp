#ifndef BACKEND_VIEW_DDS_OPERATIONS_COMMUNICATION_HPP
#define BACKEND_VIEW_DDS_OPERATIONS_COMMUNICATION_HPP

#include <functional>
#include <iostream>
#include <thread>

#include <dds/pub/Publisher.hpp>
#include <dds/sub/ddssub.hpp>
#include <rti/config/Logger.hpp>
#include <rti/util/util.hpp>

#include <backend/source/controller/operations/DepositMoney.hpp>
#include <backend/source/controller/operations/SelectFund.hpp>
#include <backend/source/controller/operations/TransferMoney.hpp>
#include <backend/source/controller/operations/WithdrawMoney.hpp>
#include <backend/source/view/dds/operations/CommunicationFactory.hpp>
#include <idl/bank.hpp>
#include <model/source/operations/signal/UpdatedFund.hpp>
#include <model/source/operations/signal/UpdatedFundType.hpp>
#include <utils/source/dds/DDSDataReader.hpp>
#include <utils/source/dds/DDSDataWriter.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>

namespace backend
{
namespace view
{
namespace dds
{
namespace operations
{

class Communication :
    public backend::view::dds::operations::CommunicationFactory,
    public utils::designPattern::SignalSubscriber<model::operations::signal::UpdatedFund>,
    public utils::designPattern::SignalSubscriber<model::operations::signal::UpdatedFundType>
{
  public:
    Communication(unsigned int domainId, unsigned int sampleCount,
                std::shared_ptr<backend::controller::operations::SelectFund> selectFundController,
                std::shared_ptr<backend::controller::operations::DepositMoney> depositMoneyController,
                std::shared_ptr<backend::controller::operations::WithdrawMoney> WithdrawMoney,
                std::shared_ptr<backend::controller::operations::TransferMoney> transferMoneyController);

    void recievedSignal(model::operations::signal::UpdatedFund signal) override;
    void recievedSignal(model::operations::signal::UpdatedFundType signal) override;

  private:
    void receivedTopicSelectFund(SelectFund selectFund) override;
    void receivedTopicDeposit(Deposit deposit) override;
    void receivedTopicWithdraw(Withdraw withdraw) override;
    void receivedTopicTransaction(Transaction transaction) override;

    void writeFundData(const FundType& fundType, int16_t amount);
    void writeSelectFundAck(const FundType& fundType);

    std::shared_ptr<backend::controller::operations::SelectFund> mSelectFundController;
    std::shared_ptr<backend::controller::operations::DepositMoney> mDepositMoneyController;
    std::shared_ptr<backend::controller::operations::WithdrawMoney> mWithdrawMoney;
    std::shared_ptr<backend::controller::operations::TransferMoney> mTransferMoneyController;
};

}  // namespace operations
}  // namespace dds
}  // namespace view
}  // namespace backend

#endif  // BACKEND_VIEW_DDS_OPERATIONS_COMMUNICATION_HPP
