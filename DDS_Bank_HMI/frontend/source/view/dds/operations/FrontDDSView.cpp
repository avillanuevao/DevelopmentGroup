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

FrontDDSView::FrontDDSView(std::shared_ptr<viewModel::dds::operations::DDSViewModel> ddsViewModel,
                           unsigned int domain_id,
                           unsigned int sample_count) :
    m_ddsViewModel(ddsViewModel),
    m_domain_id(domain_id),
    m_sample_count(sample_count),
    m_participant(std::make_shared<::dds::domain::DomainParticipant>(domain_id)),
    m_publisher(std::make_shared<::dds::pub::Publisher>(*m_participant)),
    m_writerSelectFund(m_participant, m_publisher, SELECT_FUND_TOPIC),
    m_writerDeposit(m_participant, m_publisher, DEPOSIT_TOPIC),
//    m_writerWithdraw(m_participant, m_publisher, WITHDRAW_TOPIC),
//    m_writerTransfer(m_participant, m_publisher, TRANSACTION_TOPIC),
    m_subscriber(std::make_shared<::dds::sub::Subscriber>(*m_participant)),
    m_readerSelectFundAck(m_participant, m_subscriber, SELECT_FUND_TOPIC_ACK, std::bind(&FrontDDSView::receivedTopicSelectFundAck, this, std::placeholders::_1)),
    m_readerFundData(m_participant, m_subscriber, FUND_DATA_TOPIC, std::bind(&FrontDDSView::receivedTopicFundData, this, std::placeholders::_1))
{
    utils::so::setup_signal_handlers();
    m_wait = ::dds::core::Duration(1);
    m_threadSelectFundAck = initReadingTopicThread(&FrontDDSView::readingTopicSelectFundAck);
    m_threadFundData = initReadingTopicThread(&FrontDDSView::readingTopicFundData);
}

void FrontDDSView::update(viewModel::signal::DepositMoneySignal signal)
{
    writeDeposit(signal.getAmount());
}

void FrontDDSView::update(viewModel::signal::WithdrawnMoneySignal signal)
{
    writeWithdraw(static_cast<FundType>(signal.getFundType()), signal.getAmount());
}

void FrontDDSView::update(viewModel::signal::TransferedMoneySignal signal)
{
    writeTransaction(static_cast<FundType>(signal.getOriginFundType()), static_cast<FundType>(signal.getDestinationFundType()), signal.getAmount());
}

void FrontDDSView::update(viewModel::ui::operations::signal::SelectFundSignal signal)
{
    writeSelectFund(static_cast<FundType>(signal.getFundType()));
}

void FrontDDSView::writeDeposit(int16_t amount)
{
    Deposit sampleDeposit(amount);

    m_writerDeposit.write(sampleDeposit);

    std::cout << "sample Deposit sended: " << std::endl
              << "\t[amount:" << sampleDeposit.amount() << "]" << std::endl;
}

const Transaction FrontDDSView::writeTransaction(const FundType &originFundType, const FundType &destinationFundType, int16_t amount)
{
//    Transaction sampleTransaction(originFundType, destinationFundType, amount);
//    m_writerTransfer.write(sampleTransaction);
//    std::cout << "sample Transaction sended: "
//              << static_cast<int>(sampleTransaction.fund_type_origin())
//              << " "
//              << static_cast<int>(sampleTransaction.fund_type_destination())
//              << " "
//              << sampleTransaction.amount()
//              << std::endl;

//    return sampleTransaction;
}

void FrontDDSView::writeSelectFund(FundType fundType)
{
    SelectFund sampleSelectFund(fundType);

    std::cout << "Hasta aqui llego" << std::endl;

    m_writerSelectFund.write(sampleSelectFund);

    std::cout << "sample SelectFund sended: " << std::endl
              << "\t[" << static_cast<int>(sampleSelectFund.fund_type()) << "]" << std::endl;
}

void FrontDDSView::receivedTopicSelectFundAck(SelectFundAck selectFundAck)
{
    std::cout << "SelectFund topic recieved: " << std::endl;
    std::cout << "\t" << selectFundAck << std::endl;

    model::FundType modelFundType(static_cast<model::FundType>(selectFundAck.fund_type()));

    m_ddsViewModel->updateFundType(modelFundType);
}

void FrontDDSView::readingTopicSelectFundAck()
{
    while(!utils::so::shutdown_requested)
    {
        m_readerSelectFundAck.wait(m_wait);
    }
}

void FrontDDSView::receivedTopicFundData(FundData fundData)
{
    std::cout << "FundData topic recieved: " << std::endl;
    std::cout << "\t" << fundData << std::endl;

    m_ddsViewModel->updateAmount(fundData.amount());
}

void FrontDDSView::readingTopicFundData()
{
    while(!utils::so::shutdown_requested)
    {
        m_readerFundData.wait(m_wait);
    }
}

std::thread FrontDDSView::initReadingTopicThread(void (frontend::view::dds::operations::FrontDDSView::*function)())
{
    return std::thread(function, this);
}

const Withdraw FrontDDSView::writeWithdraw(const FundType &fundType, int16_t amount)
{
//    Withdraw sampleWithdraw(fundType, amount);

//    m_writerWithdraw.write(sampleWithdraw);
//    std::cout << "withdraw topic sended: "
//              << static_cast<int>(sampleWithdraw.fund_type())
//              << " "
//              << sampleWithdraw.amount()
//              << std::endl;

//    return sampleWithdraw;
}

}
}
}
}
