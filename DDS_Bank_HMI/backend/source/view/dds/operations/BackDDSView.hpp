#ifndef BACKEND_VIEW_DDS_OPERATIONS_BACKDDSVIEW_HPP
#define BACKEND_VIEW_DDS_OPERATIONS_BACKDDSVIEW_HPP

#include <iostream>
#include <functional>
#include <thread>

#include <dds/sub/ddssub.hpp>
#include <dds/pub/Publisher.hpp>
#include <rti/util/util.hpp>
#include <rti/config/Logger.hpp>

#include <idl/bank.hpp>
#include <utils/source/dds/DDSDataReader.hpp>
#include <utils/source/dds/DDSDataWriter.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>
#include <model/source/operations/signal/UpdatedFund.hpp>
#include <model/source/operations/signal/UpdatedFundType.hpp>
#include <backend/source/controller/operations/SelectFundController.hpp>
#include <backend/source/controller/operations/DepositMoneyController.hpp>
#include <backend/source/controller/operations/WithdrawMoneyController.hpp>
#include <backend/source/controller/operations/TransferMoneyController.hpp>
#include <backend/source/view/dds/operations/BackDDSViewFactory.hpp>

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
        BackDDSView(unsigned int domainId,
                    unsigned int sampleCount,
                    std::shared_ptr<backend::controller::operations::SelectFundController> selectFundController,
                    std::shared_ptr<backend::controller::operations::DepositMoneyController> depositMoneyController,
                    std::shared_ptr<backend::controller::operations::WithdrawMoneyController> withdrawMoneyController,
                    std::shared_ptr<backend::controller::operations::TransferMoneyController> transferMoneyController);

        void recievedSignal(model::operations::signal::UpdatedFund signal);
        void recievedSignal(model::operations::signal::UpdatedFundType signal);

    private:
        void writeFundData(const FundType &fundType, int16_t amount);
        void writeSelectFundAck(const FundType &fundType);
        void receivedTopicSelectFund(SelectFund selectFund);
        void receivedTopicDeposit(Deposit deposit);
        void receivedTopicWithdraw(Withdraw withdraw);
        void receivedTopicTransaction(Transaction transaction);

        std::shared_ptr<backend::controller::operations::SelectFundController> m_selectFundController;
        std::shared_ptr<backend::controller::operations::DepositMoneyController> m_depositMoneyController;
        std::shared_ptr<backend::controller::operations::WithdrawMoneyController> m_withdrawMoneyController;
        std::shared_ptr<backend::controller::operations::TransferMoneyController> m_transferMoneyController;

};

}
}
}
}

#endif // BACKEND_VIEW_DDS_OPERATIONS_BACKDDSVIEW_HPP
