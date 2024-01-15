#ifndef DDSDATAREADER_HPP
#define DDSDATAREADER_HPP

#include <memory>

#include <dds/pub/ddspub.hpp>
#include <dds/core/ddscore.hpp>
#include <rti/config/Logger.hpp>


namespace utils {
namespace dds {

template <class TTopic>
class DDSDataReader
{
    public:
        DDSDataReader(std::shared_ptr<::dds::domain::DomainParticipant> participant,
                      std::shared_ptr<::dds::sub::Subscriber> subscriber,
                      const std::string& topicName) :
            m_participant(participant),
            m_subscriber(subscriber),
            m_topicName(topicName),
            m_topic(*m_participant, m_topicName),
            m_reader(*m_subscriber, m_topic),
            m_statusCondition(m_reader)

        {
            m_statusCondition.enabled_statuses(::dds::core::status::StatusMask::data_available());
        }

    private:
        std::shared_ptr<::dds::domain::DomainParticipant> m_participant;
        std::shared_ptr<::dds::sub::Subscriber> m_subscriber;
        const std::string& m_topicName;

        ::dds::topic::Topic<TTopic> m_topic;
        ::dds::sub::DataReader<TTopic> m_reader;
        ::dds::core::cond::StatusCondition m_statusCondition;
};

}
}

#endif // DDSDATAREADER_HPP
