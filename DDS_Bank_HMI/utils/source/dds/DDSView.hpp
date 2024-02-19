#ifndef UTILS_DDS_DDSVIEW_HPP
#define UTILS_DDS_DDSVIEW_HPP

#include <thread>

#include <dds/sub/ddssub.hpp>
#include <dds/pub/Publisher.hpp>
#include <rti/util/util.hpp>
#include <rti/config/Logger.hpp>

#include <dds/DDSDataWriter.hpp>
#include <dds/DDSDataReader.hpp>

#include <so/Shutdown.hpp>

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
        template<class TTopic>
        utils::dds::DDSDataReader<TTopic> createDataReader(const std::string& topicName, std::function<void(TTopic)> function)
        {
            return utils::dds::DDSDataReader<TTopic>(m_participant, m_subscriber, topicName, function);
        }

        template<class TTopic>
        utils::dds::DDSDataWriter<TTopic> createrDataWriter(const std::string& topicName)
        {
            return utils::dds::DDSDataWriter<TTopic>(m_participant, m_publisher, topicName);
        }

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
