#ifndef UTILS_DDS_DDSVIEW_HPP
#define UTILS_DDS_DDSVIEW_HPP

#include <thread>

#include <dds/sub/ddssub.hpp>
#include <dds/pub/Publisher.hpp>
#include <rti/util/util.hpp>
#include <rti/config/Logger.hpp>

namespace utils
{
namespace dds
{

class DDSView
{
    public:
        DDSView(unsigned int domainId,
                unsigned int sampleCount);

    protected:
        unsigned int m_domainId;
        unsigned int m_sampleCount;

        ::dds::core::Duration m_wait;
        std::shared_ptr<::dds::domain::DomainParticipant> m_participant;
        std::shared_ptr<::dds::pub::Publisher> m_publisher;
        std::shared_ptr<::dds::sub::Subscriber> m_subscriber;
        std::map<std::string, std::thread> m_threadsForReading;
};

}
}


#endif // UTILS_DDS_DDSVIEW_HPP
