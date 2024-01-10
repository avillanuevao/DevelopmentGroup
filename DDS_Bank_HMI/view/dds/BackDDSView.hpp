#ifndef BACKDDSVIEW_HPP
#define BACKDDSVIEW_HPP

#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>
#include <rti/config/Logger.hpp>

#include <idl/bank.hpp>

namespace view {
    namespace dds {
        class BackDDSView
        {
            public:
                BackDDSView(unsigned int domain_id, unsigned int sample_count);

            private:
                unsigned int m_domain_id;
                unsigned int m_sample_count;

                std::shared_ptr<::dds::domain::DomainParticipant> m_participant;
                std::shared_ptr<::dds::sub::Subscriber> m_subscriber;
        };
    }
}



#endif // BACKDDSVIEW_HPP
