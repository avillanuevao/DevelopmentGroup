#ifndef FRONTDDSVIEW_HPP
#define FRONTDDSVIEW_HPP

#include <iostream>
#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>  // for sleep()
#include <rti/config/Logger.hpp>  // for logging

#include <idl/bank.hpp>

namespace view
{
    namespace dds
    {
        class FrontDDSView
        {
        public:
            FrontDDSView(unsigned int domain_id, unsigned int sample_count);
        private:
            unsigned int m_domain_id;
            unsigned int m_sample_count;
            ::dds::domain::DomainParticipant m_participant;
            ::dds::pub::Publisher m_publisher;
            ::dds::topic::Topic<HelloWorld> m_topic;
            ::dds::topic::Topic<Reset> m_topicReset;
            ::dds::topic::Topic<Transaction> m_topicTransaction;
            ::dds::pub::DataWriter<HelloWorld> m_writer;
            ::dds::pub::DataWriter<Transaction> m_writerTransaction;
            ::dds::pub::DataWriter<Reset> m_writerReset;
        };
    }
}


#endif // FRONTDDSVIEW_HPP
