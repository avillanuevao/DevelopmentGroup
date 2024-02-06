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

FrontDDSView::FrontDDSView(unsigned int domainId,
                           unsigned int sampleCount,
                           std::shared_ptr<viewModel::dds::operations::DDSViewModel> ddsViewModel) :
    utils::dds::DDSView(domainId, sampleCount),
    m_ddsViewModel(ddsViewModel),
    m_writerSelectFund(m_participant, m_publisher, SELECT_FUND_TOPIC),
    m_writerDeposit(m_participant, m_publisher, DEPOSIT_TOPIC),
    m_writerWithdraw(m_participant, m_publisher, WITHDRAW_TOPIC),
    m_writerTransfer(m_participant, m_publisher, TRANSACTION_TOPIC),
    m_readerSelectFundAck(m_participant, m_subscriber, SELECT_FUND_TOPIC_ACK, std::bind(&FrontDDSView::receivedTopicSelectFundAck, this, std::placeholders::_1)),
    m_readerFundData(m_participant, m_subscriber, FUND_DATA_TOPIC, std::bind(&FrontDDSView::receivedTopicFundData, this, std::placeholders::_1))
{
    utils::so::setup_signal_handlers();

    m_threadsForReading[SELECT_FUND_TOPIC_ACK] = initReadingTopicThread(&FrontDDSView::readingTopicSelectFundAck);
    m_threadsForReading[FUND_DATA_TOPIC] = initReadingTopicThread(&FrontDDSView::readingTopicFundData);
}

void FrontDDSView::update(viewModel::signal::DepositMoneySignal signal)
{
    writeDeposit(signal.getAmount());
}

void FrontDDSView::update(viewModel::ui::operations::signal::WithdrawnMoneySignal signal)
{
    writeWithdraw(signal.getAmount());
}

void FrontDDSView::update(viewModel::signal::TransferedMoneySignal signal)
{
    writeTransaction(static_cast<FundType>(signal.getDestinationFundType()), signal.getAmount());
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

void FrontDDSView::writeWithdraw(int16_t amount)
{
    Withdraw sampleWithdraw(amount);

    m_writerWithdraw.write(sampleWithdraw);

    std::cout << "sample Withdraw sended:  "
              << "\t[amount:" << sampleWithdraw.amount() << "]" << std::endl;
}

void FrontDDSView::writeTransaction(const FundType &destinationFundType, int16_t amount)
{
    Transaction sampleTransaction(destinationFundType, amount);

    m_writerTransfer.write(sampleTransaction);

    std::cout << "sample Transaction sended: " << std::endl
              << "\t[fundTypeDestination: " << static_cast<int>(sampleTransaction.fund_type_destination())
              << ", amount: " << sampleTransaction.amount() << "]" << std::endl;
}

void FrontDDSView::writeSelectFund(FundType fundType)
{
    SelectFund sampleSelectFund(fundType);

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

    model::FundType modelFundType(static_cast<model::FundType>(fundData.fund_type()));

    m_ddsViewModel->updateAmount(modelFundType, fundData.amount());
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

}
}
}
}
