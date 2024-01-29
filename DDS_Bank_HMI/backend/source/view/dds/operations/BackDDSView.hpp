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
#include <model/source/signal/MoneyDepositedSignal.hpp>
#include <model/source/signal/MoneyWithdrawnSignal.hpp>
#include <model/source/signal/MoneyTransferedSignal.hpp>
#include <model/source/AllFunds.hpp>
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
        public utils::designPattern::SignalSubscriber<model::signal::MoneyDepositedSignal>,
        public utils::designPattern::SignalSubscriber<model::signal::MoneyWithdrawnSignal>
        public utils::designPattern::SignalSubscriber<model::signal::MoneyTransferedSignal>
{
    public:
        BackDDSView(std::shared_ptr<model::AllFunds> allFunds, unsigned int domainId, unsigned int sampleCount);
        ~BackDDSView();

        void update(model::signal::MoneyDepositedSignal signal);
        void update(model::signal::MoneyTransferedSignal signal);
        void update(model::signal::MoneyWithdrawnSignal signal);

    private:
        void configureDeposit(Deposit deposit);
        void initDepositUseCase();
        void configureTransaction(Transaction transaction);
        void initTransactionUseCase();
        const FundData writeFundData(const FundType &fundType, int16_t amount);

        void receivedTopicWithdraw(Withdraw withdraw);
        void readingTopicWithdraw();


        const std::shared_ptr<model::AllFunds> m_allFunds;
        std::unique_ptr<backend::controller::operation::TransferMoneyController> m_transferMoneyController;
        unsigned int m_domainId;
        unsigned int m_sampleCount;
        std::unique_ptr<backend::controller::operation::DepositMoneyController> m_depositMoneyController;
        std::unique_ptr<backend::controller::operation::WithdrawMoneyController> m_withdrawMoneyController;
        std::shared_ptr<::dds::domain::DomainParticipant> m_participant;
        std::shared_ptr<::dds::sub::Subscriber> m_subscriber;
        utils::dds::DDSDataReader<Deposit> m_readerDeposit;
        utils::dds::DDSDataReader<Withdraw> m_readerWithdraw;
        std::shared_ptr<std::thread> m_threadDeposit;
        std::shared_ptr<std::thread> m_threadWithdraw;
        ::dds::core::Duration m_wait;
        utils::dds::DDSDataReader<Transaction> m_readerTransaction;
        std::shared_ptr<std::thread> m_threadTransaction;
        std::shared_ptr<::dds::pub::Publisher> m_publisher;
        utils::dds::DDSDataWriter<FundData> m_writerFundData;
};

}
}
}
}

#endif // BACKDDSVIEW_HPP
