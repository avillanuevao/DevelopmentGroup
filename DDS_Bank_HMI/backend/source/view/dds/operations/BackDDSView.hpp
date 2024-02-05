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
#include <utils/source/dds/DDSDataReader.hpp>
#include <utils/source/dds/DDSDataWriter.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>
#include <model/source/signal/UpdatedFundSignal.hpp>
#include <model/source/signal/UpdatedFundTypeSignal.hpp>
#include <backend/source/controller/operation/SelectFundController.hpp>
#include <backend/source/controller/operation/DepositMoneyController.hpp>
#include <backend/source/controller/operation/WithdrawMoneyController.hpp>
#include <backend/source/controller/operation/TransferMoneyController.hpp>

namespace backend
{
namespace view
{
namespace dds
{
namespace operations
{

class BackDDSView :
        public utils::designPattern::SignalSubscriber<model::signal::UpdatedFundSignal>,
        public utils::designPattern::SignalSubscriber<model::signal::UpdatedFundTypeSignal>
{
    public:
        BackDDSView(std::shared_ptr<backend::controller::operation::SelectFundController> selectFundController,
                    std::shared_ptr<backend::controller::operation::DepositMoneyController> depositMoneyController,
                    unsigned int domainId,
                    unsigned int sampleCount);
        ~BackDDSView();

        void update(model::signal::UpdatedFundSignal signal);
        void update(model::signal::UpdatedFundTypeSignal signal);

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
        void writeSelectFund(const FundType &fundType);

        std::thread initReadingTopicThread(void (backend::view::dds::operations::BackDDSView::*function)());
        void deleteThread(std::shared_ptr<std::thread> thread);

        std::shared_ptr<backend::controller::operation::SelectFundController> m_selectFundController;
        std::shared_ptr<backend::controller::operation::DepositMoneyController> m_depositMoneyController;
        unsigned int m_domainId;
        unsigned int m_sampleCount;

        //std::unique_ptr<backend::controller::operation::WithdrawMoneyController> m_withdrawMoneyController;
        //std::unique_ptr<backend::controller::operation::TransferMoneyController> m_transferMoneyController;
        std::shared_ptr<::dds::domain::DomainParticipant> m_participant;
        std::shared_ptr<::dds::sub::Subscriber> m_subscriber;
        utils::dds::DDSDataReader<SelectFund> m_readerSelectFund;
        utils::dds::DDSDataReader<Deposit> m_readerDeposit;
        utils::dds::DDSDataReader<Withdraw> m_readerWithdraw;
        utils::dds::DDSDataReader<Transaction> m_readerTransaction;
        std::shared_ptr<::dds::pub::Publisher> m_publisher;
        utils::dds::DDSDataWriter<SelectFund> m_writerSelectFund;
        utils::dds::DDSDataWriter<FundData> m_writerFundData;
        ::dds::core::Duration m_wait;
        std::thread m_threadSelectFund;
        std::shared_ptr<std::thread> m_threadDeposit;
        std::shared_ptr<std::thread> m_threadWithdraw;
        std::shared_ptr<std::thread> m_threadTransaction;
};

}
}
}
}

#endif // BACKDDSVIEW_HPP
