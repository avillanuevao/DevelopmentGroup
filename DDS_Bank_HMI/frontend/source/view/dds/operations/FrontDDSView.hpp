#ifndef FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEW_HPP
#define FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEW_HPP

#include <iostream>
#include <thread>

#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include <rti/util/util.hpp>
#include <rti/config/Logger.hpp>

#include <idl/bank.hpp>
#include <model/source/AllFunds.hpp>
#include <utils/source/dds/DDSDataWriter.hpp>
#include <utils/source/dds/DDSDataReader.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>
#include <frontend/source/viewModel/dds/operations/DDSViewModel.hpp>
#include <frontend/source/viewModel/signal/DepositMoneySignal.hpp>
#include <frontend/source/viewModel/signal/WithdrawnMoneySignal.hpp>
#include <frontend/source/viewModel/signal/TransferedMoneySignal.hpp>
#include <frontend/source/viewModel/ui/operations/signal/SelectFundSignal.hpp>

namespace frontend
{
namespace view
{
namespace dds
{
namespace operations
{
class FrontDDSView :
        public utils::designPattern::SignalSubscriber<viewModel::signal::DepositMoneySignal>,
        public utils::designPattern::SignalSubscriber<viewModel::signal::WithdrawnMoneySignal>,
        public utils::designPattern::SignalSubscriber<frontend::viewModel::signal::TransferedMoneySignal>,
        public utils::designPattern::SignalSubscriber<frontend::viewModel::ui::operations::signal::SelectFundSignal>
{
    public:
        FrontDDSView(std::shared_ptr<frontend::viewModel::dds::operations::DDSViewModel> ddsViewModel,
                     unsigned int domain_id,
                     unsigned int sample_count);

        void update(viewModel::signal::DepositMoneySignal signal);
        void update(viewModel::signal::WithdrawnMoneySignal signal);
        void update(frontend::viewModel::signal::TransferedMoneySignal signal);
        void update(frontend::viewModel::ui::operations::signal::SelectFundSignal signal);

    private:
        const Deposit writeDeposit(int16_t amount);
        const Withdraw writeWithdraw(const FundType& fundType, int16_t amount);
        const Transaction writeTransaction(const FundType& originFundType, const FundType& destinationFundType, int16_t amount);
        const SelectFund writeSelectFund(FundType fundType);
        void receivedTopicSelectFund(SelectFund selectFund);
        void readingTopicSelectFund();
        void receivedTopicFundData(FundData fundData);
        void readingTopicFundData();

        std::thread initReadingTopicThread(void (frontend::view::dds::operations::FrontDDSView::*function)());

        std::shared_ptr<frontend::viewModel::dds::operations::DDSViewModel> m_ddsViewModel;
        unsigned int m_domain_id;
        unsigned int m_sample_count;

        std::shared_ptr<::dds::domain::DomainParticipant> m_participant;
        std::shared_ptr<::dds::pub::Publisher> m_publisher;
        utils::dds::DDSDataWriter<SelectFund> m_writerSelectFund;
        utils::dds::DDSDataWriter<Deposit> m_writerDeposit;
//        utils::dds::DDSDataWriter<Withdraw> m_writerWithdraw;
//        utils::dds::DDSDataWriter<Transaction> m_writerTransfer;
        std::shared_ptr<::dds::sub::Subscriber> m_subscriber;
//        utils::dds::DDSDataReader<SelectFund> m_readerSelectFund;
        utils::dds::DDSDataReader<FundData> m_readerFundData;
        std::thread m_threadSelectFund;
        std::thread m_threadFundData;
        ::dds::core::Duration m_wait;
};

}
}
}
}

#endif // FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEW_HPP
