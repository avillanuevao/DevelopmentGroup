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

BackDDSView::BackDDSView(std::shared_ptr<model::AllFunds> allFunds, unsigned int domainId, unsigned int sampleCount):
    m_allFunds(allFunds),
    m_depositMoneyController(new backend::controller::operation::DepositMoneyController(m_allFunds)),
    m_domainId(domainId),
    m_sampleCount(sampleCount),
    m_participant(std::make_shared<::dds::domain::DomainParticipant>(m_domainId)),
    m_subscriber(std::make_shared<::dds::sub::Subscriber>(*m_participant)),
    m_readerDeposit(m_participant, m_subscriber, DEPOSIT_TOPIC, std::bind(&BackDDSView::configureDeposit, this, std::placeholders::_1)),
    m_publisher(std::make_shared<::dds::pub::Publisher>(*m_participant)),
    m_writerFundData(m_participant, m_publisher, FUND_DATA_TOPIC)

{
    std::cout << "BackDDSView" << std::endl;
    utils::so::setup_signal_handlers();
    m_wait = ::dds::core::Duration(1);
    m_threadDeposit = std::make_shared<std::thread>(&BackDDSView::initDepositUseCase, this);
}

BackDDSView::~BackDDSView()
{
    std::cout << "~BackDDSView" << std::endl;
    m_threadDeposit->join();
    m_threadDeposit = nullptr;
}

void BackDDSView::update(model::signal::MoneyDepositedSignal signal)
{
    std::cout << "update BackddsView" << std::endl;
    writeFundData(signal.getFundType(), signal.getAmount());
}

void BackDDSView::configureDeposit(Deposit deposit)
{
    std::cout << "Data obtenido: " << std::endl;
    std::cout << "\t" << deposit << std::endl;
    m_depositMoneyController->doDeposit(deposit);

}

void BackDDSView::initDepositUseCase()
{
    std::cout << "initDepositUseCase" << std::endl;
    while(!utils::so::shutdown_requested)
    {
        std::cout << "initDepositUseCase-while" << std::endl;
        m_readerDeposit.wait(m_wait);
    }
}

const FundData BackDDSView::writeFundData(const FundType &fund_type, int16_t amount)
{
    FundData sampleFundData(fund_type, amount);

    m_writerFundData.write(sampleFundData);
    std::cout << "topic sended: "
              << static_cast<int>(sampleFundData.fund_type())
              << " "
              << sampleFundData.amount();

    return sampleFundData;
}

}
}
}
}
