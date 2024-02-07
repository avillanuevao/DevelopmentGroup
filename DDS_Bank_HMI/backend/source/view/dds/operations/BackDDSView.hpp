#ifndef BACKDDSVIEW_HPP
#define BACKDDSVIEW_HPP

#include <iostream>
#include <functional>
#include <thread>

#include <dds/sub/ddssub.hpp>
#include <dds/pub/Publisher.hpp>
#include <rti/util/util.hpp>
#include <rti/config/Logger.hpp>

#include <idl/bank.hpp>
#include <utils/source/dds/DDSView.hpp>
#include <utils/source/dds/DDSDataReader.hpp>
#include <utils/source/dds/DDSDataWriter.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>
#include <model/source/operations/signal/UpdatedFundSignal.hpp>
#include <model/source/operations/signal/UpdatedFundTypeSignal.hpp>
#include <backend/source/controller/operations/SelectFundController.hpp>
#include <backend/source/controller/operations/DepositMoneyController.hpp>
#include <backend/source/controller/operations/WithdrawMoneyController.hpp>
#include <backend/source/controller/operations/TransferMoneyController.hpp>

namespace backend
{
namespace view
{
namespace dds
{
namespace operations
{

class BackDDSView :
        public utils::dds::DDSView,
        public utils::designPattern::SignalSubscriber<model::operations::signal::UpdatedFundSignal>,
        public utils::designPattern::SignalSubscriber<model::operations::signal::UpdatedFundTypeSignal>
{
    public:
        BackDDSView(unsigned int domainId,
                    unsigned int sampleCount,
                    std::shared_ptr<backend::controller::operations::SelectFundController> selectFundController,
                    std::shared_ptr<backend::controller::operations::DepositMoneyController> depositMoneyController,
                    std::shared_ptr<backend::controller::operations::WithdrawMoneyController> withdrawMoneyController,
                    std::shared_ptr<backend::controller::operations::TransferMoneyController> transferMoneyController);
        ~BackDDSView();

        void update(model::operations::signal::UpdatedFundSignal signal);
        void update(model::operations::signal::UpdatedFundTypeSignal signal);

    private:
        void receivedTopicSelectFund(SelectFund selectFund);
        void readingTopicSelectFund();
        void receivedTopicDeposit(Deposit deposit);
        void readingTopicDeposit();
        void receivedTopicWithdraw(Withdraw withdraw);
        void readingTopicWithdraw();
        void receivedTopicTransaction(Transaction transaction);
        void readingTopicTransaction();
        void writeFundData(const FundType &fundType, int16_t amount);
        void writeSelectFundAck(const FundType &fundType);

        std::thread initReadingTopicThread(void (backend::view::dds::operations::BackDDSView::*function)());

        std::shared_ptr<backend::controller::operations::SelectFundController> m_selectFundController;
        std::shared_ptr<backend::controller::operations::DepositMoneyController> m_depositMoneyController;
        std::shared_ptr<backend::controller::operations::WithdrawMoneyController> m_withdrawMoneyController;
        std::shared_ptr<backend::controller::operations::TransferMoneyController> m_transferMoneyController;

        utils::dds::DDSDataReader<SelectFund> m_readerSelectFund;
        utils::dds::DDSDataReader<Deposit> m_readerDeposit;
        utils::dds::DDSDataReader<Withdraw> m_readerWithdraw;
        utils::dds::DDSDataReader<Transaction> m_readerTransaction;
        utils::dds::DDSDataWriter<SelectFundAck> m_writerSelectFundAck;
        utils::dds::DDSDataWriter<FundData> m_writerFundData;
};

}
}
}
}

#endif // BACKDDSVIEW_HPP
