#ifndef FRONTDDSVIEW_HPP
#define FRONTDDSVIEW_HPP

#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>
#include <rti/config/Logger.hpp>

#include <idl/bank.hpp>

#include <utils/dds/DDSDataWriter.hpp>

namespace view
{
    namespace dds
    {
        class FrontDDSView
        {
            public:
                FrontDDSView(unsigned int domain_id, unsigned int sample_count);

                const Deposit writeDeposit(const FundType& fund_type, int16_t amount);

            private:
                unsigned int m_domain_id;
                unsigned int m_sample_count;

                std::shared_ptr<::dds::domain::DomainParticipant> m_participant;
                std::shared_ptr<::dds::pub::Publisher> m_publisher;

                utils::dds::DDSDataWriter<Deposit> m_writerDeposit;
        };
    }
}


#endif // FRONTDDSVIEW_HPP
