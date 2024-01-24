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
#include <utils/dds/DDSDataReader.hpp>
#include <utils/dds/DDSDataWriter.hpp>
#include <utils/designPattern/SignalSubscriber.hpp>
#include <model/source/signal/MoneyDepositedSignal.hpp>
#include <model/source/AllFunds.hpp>
#include <backend/source/controller/operation/DepositMoneyController.hpp>

namespace backend
{
namespace view
{
namespace dds
{
namespace operations
{

class BackDDSView :
        public utils::designPattern::SignalSubscriber<model::signal::MoneyDepositedSignal>
{
    public:
        BackDDSView(std::shared_ptr<model::AllFunds> allFunds, unsigned int domainId, unsigned int sampleCount);
        ~BackDDSView();
        void update(model::signal::MoneyDepositedSignal signal);

    private:
        void configureDeposit(Deposit deposit);
        void initDepositUseCase();
        const FundData writeFundData(const FundType &fundType, int16_t amount);


        const std::shared_ptr<model::AllFunds> m_allFunds;
        std::unique_ptr<backend::controller::operation::DepositMoneyController> m_depositMoneyController;
        unsigned int m_domainId;
        unsigned int m_sampleCount;
        std::shared_ptr<::dds::domain::DomainParticipant> m_participant;
        std::shared_ptr<::dds::sub::Subscriber> m_subscriber;
        utils::dds::DDSDataReader<Deposit> m_readerDeposit;
        std::shared_ptr<std::thread> m_threadDeposit;
        ::dds::core::Duration m_wait;
        std::shared_ptr<::dds::pub::Publisher> m_publisher;
        utils::dds::DDSDataWriter<FundData> m_writerFundData;
};

}
}
}
}

#endif // BACKDDSVIEW_HPP
