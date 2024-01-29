#include "FrontDDSView.hpp"
#include <utils/source/so/Shutdown.hpp>

namespace frontend
{
namespace view
{
namespace dds
{
namespace operations
{

FrontDDSView::FrontDDSView(std::shared_ptr<model::AllFunds> allFunds, unsigned int domain_id, unsigned int sample_count) :
    m_allFunds(allFunds),
    m_ddsViewModel(std::make_shared<frontend::viewModel::dds::operations::DDSViewModel>(allFunds)),
    m_domain_id(domain_id),
    m_sample_count(sample_count),
    m_participant(std::make_shared<::dds::domain::DomainParticipant>(domain_id)),
    m_publisher(std::make_shared<::dds::pub::Publisher>(*m_participant)),
    m_writerDeposit(m_participant, m_publisher, DEPOSIT_TOPIC),
    m_writerTransfer(m_participant, m_publisher, TRANSACTION_TOPIC),
    m_subscriber(std::make_shared<::dds::sub::Subscriber>(*m_participant)),
    m_readerFundData(m_participant, m_subscriber, FUND_DATA_TOPIC, std::bind(&FrontDDSView::configureFundData, this, std::placeholders::_1))
{
    utils::so::setup_signal_handlers();
    m_wait = ::dds::core::Duration(1);
    m_threadFundData = std::make_shared<std::thread>(&FrontDDSView::initReaderFundData, this);
}

void FrontDDSView::update(viewModel::signal::DepositMoneySignal signal)
{
    writeDeposit(static_cast<FundType>(signal.getFundType()), signal.getAmount());
}

void FrontDDSView::update(viewModel::signal::TransferedMoneySignal signal)
{
    writeTransaction(static_cast<FundType>(signal.getOriginFundType()), static_cast<FundType>(signal.getDestinationFundType()), signal.getAmount());
}

const Deposit FrontDDSView::writeDeposit(const FundType &fund_type, int16_t amount)
{
    Deposit sampleDeposit(fund_type, amount);

    m_writerDeposit.write(sampleDeposit);
    std::cout << "topic sended: "
              << static_cast<int>(sampleDeposit.fund_type())
              << " "
              << sampleDeposit.amount()
              << std::endl;

    return sampleDeposit;
}

const Transaction FrontDDSView::writeTransaction(const FundType &originFundType, const FundType &destinationFundType, int16_t amount)
{
    Transaction sampleTransaction(originFundType, destinationFundType, amount);
    m_writerTransfer.write(sampleTransaction);
    std::cout << "topic sended: "
              << static_cast<int>(sampleTransaction.fund_type_origin())
              << " "
              << static_cast<int>(sampleTransaction.fund_type_destination())
              << " "
              << sampleTransaction.amount()
              << std::endl;

    return sampleTransaction;
}

void FrontDDSView::configureFundData(FundData fundData)
{
    std::cout << "Data obtenido: " << std::endl;
    std::cout << "\t" << fundData << std::endl;
    //TODO: ¿Que sentido tiene que updateModel contenga 3 variables?
    m_ddsViewModel->updateModel(model::Operation(
                                    model::FundType::NONE, static_cast<model::FundType>(fundData.fund_type()), fundData.amount()));
}

void FrontDDSView::initReaderFundData()
{
    while(!utils::so::shutdown_requested)
    {
        m_readerFundData.wait(m_wait);
    }
}

}
}
}
}
