#ifndef FRONTDDSVIEW_HPP
#define FRONTDDSVIEW_HPP

#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>
#include <rti/config/Logger.hpp>

#include <idl/bank.hpp>
#include <utils/dds/DDSDataWriter.hpp>
#include <utils/designPattern/SignalSubscriber.hpp>
#include <frontend/viewModel/signal/DepositMoneySignal.hpp>

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
        FrontDDSView(unsigned int domain_id, unsigned int sample_count);

        void update(viewModel::signal::DepositMoneySignal signal);

    private:
        const Deposit writeDeposit(const FundType& fund_type, int16_t amount);

        unsigned int m_domain_id;
        unsigned int m_sample_count;

        std::shared_ptr<::dds::domain::DomainParticipant> m_participant;
        std::shared_ptr<::dds::pub::Publisher> m_publisher;

        utils::dds::DDSDataWriter<Deposit> m_writerDeposit;
};

}
}
}
}

#endif // FRONTDDSVIEW_HPP
