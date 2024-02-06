#include "DDSView.hpp"

namespace utils
{
namespace dds
{

DDSView::DDSView(unsigned int domainId,
                 unsigned int sampleCount):
    m_domainId(domainId),
    m_sampleCount(sampleCount),
    m_participant(std::make_shared<::dds::domain::DomainParticipant>(m_domainId)),
    m_publisher(std::make_shared<::dds::pub::Publisher>(*m_participant)),
    m_subscriber(std::make_shared<::dds::sub::Subscriber>(*m_participant))
{
    m_wait = ::dds::core::Duration(1);
}

}
}
