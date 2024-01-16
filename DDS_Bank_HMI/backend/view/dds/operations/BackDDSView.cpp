#include "BackDDSView.hpp"
#include <utils/so/Shutdown.hpp>

namespace backend
{
namespace view
{
namespace dds
{
namespace operations
{

BackDDSView::BackDDSView(unsigned int domainId, unsigned int sampleCount):
    m_domainId(domainId),
    m_sampleCount(sampleCount),
    m_participant(std::make_shared<::dds::domain::DomainParticipant>(m_domainId)),
    m_subscriber(std::make_shared<::dds::sub::Subscriber>(*m_participant)),
    m_readerDeposit(m_participant, m_subscriber, DEPOSIT_TOPIC, std::bind(&BackDDSView::configureDeposit, this, std::placeholders::_1))
{
    utils::so::setup_signal_handlers();
    m_wait = ::dds::core::Duration(1);
    m_threadDeposit = std::make_shared<std::thread>(&BackDDSView::initDepositUseCase, this);
}

BackDDSView::~BackDDSView()
{
    m_threadDeposit->join();
    m_threadDeposit = nullptr;
}

void BackDDSView::configureDeposit(Deposit deposit)
{
    std::cout << "Data obtenido: " << std::endl;
    std::cout << "\t" << deposit << std::endl;
}

void BackDDSView::initDepositUseCase()
{
    while(!utils::so::shutdown_requested)
    {
        m_readerDeposit.wait(m_wait);
    }
}

}
}
}
}
