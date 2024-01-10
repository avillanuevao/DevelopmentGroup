#include "FrontDDSView.hpp"

namespace view
{
    namespace dds
    {

        FrontDDSView::FrontDDSView(unsigned int domain_id, unsigned int sample_count) :
            m_domain_id(domain_id),
            m_sample_count(sample_count),
            m_participant(std::make_shared<::dds::domain::DomainParticipant>(domain_id)),
            m_publisher(std::make_shared<::dds::pub::Publisher>(*m_participant)),
            m_writerDeposit(m_participant, m_publisher, DEPOSIT_TOPIC)
        {

        }

        const Deposit FrontDDSView::writeDeposit(const FundType &fund_type, int16_t amount)
        {
            Deposit sampleDeposit(fund_type, amount);

            m_writerDeposit.write(sampleDeposit);
            std::cout << "topic sended: "
                      << static_cast<int>(sampleDeposit.fund_type())
                      << " "
                      << sampleDeposit.amount();

            return sampleDeposit;
        }


    }

}
