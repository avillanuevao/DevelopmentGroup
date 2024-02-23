#ifndef BACKEND_VIEW_DDS_OPERATIONS_BACKDDSVIEW_HPP
#define BACKEND_VIEW_DDS_OPERATIONS_BACKDDSVIEW_HPP

#include <functional>
#include <iostream>
#include <thread>

#include <dds/pub/Publisher.hpp>
#include <dds/sub/ddssub.hpp>
#include <rti/config/Logger.hpp>
#include <rti/util/util.hpp>

#include <idl/bank.hpp>

#include <backend/source/controller/operations/DepositMoney.hpp>
#include <backend/source/controller/operations/SelectFund.hpp>
#include <backend/source/controller/operations/TransferMoney.hpp>
#include <backend/source/controller/operations/WithdrawMoney.hpp>
#include <backend/source/view/dds/operations/BackDDSViewFactory.hpp>
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

class BackDDSView :
    public backend::view::dds::operations::BackDDSViewFactory,
    public utils::designPattern::SignalSubscriber<model::operations::signal::UpdatedFund>,
    public utils::designPattern::SignalSubscriber<model::operations::signal::UpdatedFundType>
{
  public:
    BackDDSView(unsigned int domainId, unsigned int sampleCount,
                std::shared_ptr<backend::controller::operations::SelectFund> selectFundController,
                std::shared_ptr<backend::controller::operations::DepositMoney> depositMoneyController,
                std::shared_ptr<backend::controller::operations::WithdrawMoney> WithdrawMoney,
                std::shared_ptr<backend::controller::operations::TransferMoney> transferMoneyController);

    void recievedSignal(model::operations::signal::UpdatedFund signal);
    void recievedSignal(model::operations::signal::UpdatedFundType signal);

  private:
    void receivedTopicSelectFund(SelectFund selectFund) override;
    void receivedTopicDeposit(Deposit deposit) override;
    void receivedTopicWithdraw(Withdraw withdraw) override;
    void receivedTopicTransaction(Transaction transaction) override;

    void writeFundData(const FundType &fundType, int16_t amount);
    void writeSelectFundAck(const FundType &fundType);

    std::shared_ptr<backend::controller::operations::SelectFund> m_selectFundController;
    std::shared_ptr<backend::controller::operations::DepositMoney> m_depositMoneyController;
    std::shared_ptr<backend::controller::operations::WithdrawMoney> m_WithdrawMoney;
    std::shared_ptr<backend::controller::operations::TransferMoney> m_transferMoneyController;
};

}  // namespace operations
}  // namespace dds
}  // namespace view
}  // namespace backend

#endif  // BACKEND_VIEW_DDS_OPERATIONS_BACKDDSVIEW_HPP
