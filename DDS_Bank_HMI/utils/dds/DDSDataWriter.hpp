#ifndef DDSDATAWRITER_HPP
#define DDSDATAWRITER_HPP

#include <memory>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>
#include <rti/config/Logger.hpp>

namespace utils {
namespace dds {

template <class TTopic>
class DDSDataWriter
{
    public:
        DDSDataWriter(std::shared_ptr<::dds::domain::DomainParticipant> participant,
                      std::shared_ptr<::dds::pub::Publisher> publisher,
                      const std::string& topicName) :
            m_participant(participant),
            m_publisher(publisher),
            m_topicName(topicName),
            m_topic(*m_participant, m_topicName),
            m_dataWriter(*m_publisher, m_topic)
        {

        }

        void write(TTopic sample)
        {
            m_dataWriter.write(sample);
        }

    private:
        std::shared_ptr<::dds::domain::DomainParticipant> m_participant;
        std::shared_ptr<::dds::pub::Publisher> m_publisher;
        const std::string& m_topicName;
        ::dds::topic::Topic<TTopic> m_topic;
        ::dds::pub::DataWriter<TTopic> m_dataWriter;
};

}
}

#endif // DDSDATAWRITER_HPP
