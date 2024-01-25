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

namespace frontend
{
namespace view
{
namespace dds
{
namespace operations
{

class FrontDDSView: public utils::designPattern::SignalSubscriber<viewModel::signal::DepositMoneySignal>
{
    public:
        FrontDDSView(std::shared_ptr<model::AllFunds> allFunds, unsigned int domain_id, unsigned int sample_count);

        void update(viewModel::signal::DepositMoneySignal signal);

    private:
        const Deposit writeDeposit(const FundType& fund_type, int16_t amount);
        void configureFundData(FundData fundData);
        void initReaderFundData();

        unsigned int m_domain_id;
        unsigned int m_sample_count;

        const std::shared_ptr<model::AllFunds> m_allFunds;
        std::shared_ptr<frontend::viewModel::dds::operations::DDSViewModel> m_ddsViewModel;
        std::shared_ptr<::dds::domain::DomainParticipant> m_participant;
        std::shared_ptr<::dds::pub::Publisher> m_publisher;
        utils::dds::DDSDataWriter<Deposit> m_writerDeposit;
        std::shared_ptr<::dds::sub::Subscriber> m_subscriber;
        utils::dds::DDSDataReader<FundData> m_readerFundData;
        std::shared_ptr<std::thread> m_threadFundData;
        ::dds::core::Duration m_wait;
};

}
}
}
}

#endif // FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEW_HPP
