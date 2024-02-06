#ifndef DDSDATAREADER_HPP
#define DDSDATAREADER_HPP

#include <memory>

#include <dds/sub/ddssub.hpp>
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
                      const std::string& topicName,
                      std::function<void(TTopic)> function) :
            m_participant(participant),
            m_subscriber(subscriber),
            m_topicName(topicName),
            m_functionRecieveTopic(function),
            m_topic(*m_participant, m_topicName),
            m_reader(*m_subscriber, m_topic),
            m_statusCondition(m_reader)

        {
            m_statusCondition.enabled_statuses(::dds::core::status::StatusMask::data_available());
            m_statusCondition.extensions().handler(std::bind(&DDSDataReader::getSample, this));
        }

        void wait(::dds::core::Duration seconds)
        {
            //std::cout << "esperando..." << std::endl;
            ::dds::core::cond::WaitSet waitset;
            waitset += m_statusCondition;
            waitset.dispatch(seconds);
        }

    private:
        void getSample()
        {
            ::dds::sub::LoanedSamples<TTopic> samples = m_reader->take();
            for(auto sample : samples)
            {
                if(sample.info().valid())
                {
                    m_functionRecieveTopic(sample.data());
                }
            }

        }


        std::shared_ptr<::dds::domain::DomainParticipant> m_participant;
        std::shared_ptr<::dds::sub::Subscriber> m_subscriber;
        const std::string& m_topicName;
        std::function<void(TTopic)> m_functionRecieveTopic;
        ::dds::topic::Topic<TTopic> m_topic;
        ::dds::sub::DataReader<TTopic> m_reader;
        ::dds::core::cond::StatusCondition m_statusCondition;
};

}
}

#endif // DDSDATAREADER_HPP
