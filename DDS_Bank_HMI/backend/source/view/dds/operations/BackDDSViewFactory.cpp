#include "BackDDSViewFactory.hpp"
#include <utils/source/so/Shutdown.hpp>

namespace backend
{
namespace view
{
namespace dds
{
namespace operations
{

BackDDSViewFactory::BackDDSViewFactory(unsigned int domainId,
                                       unsigned int sampleCount) :
    utils::dds::DDSView(domainId, sampleCount),
    m_readerSelectFund(createDataReader<SelectFund>(SELECT_FUND_TOPIC, std::bind(&BackDDSViewFactory::receivedTopicSelectFund, this, std::placeholders::_1))),
    m_readerDeposit(createDataReader<Deposit>(DEPOSIT_TOPIC, std::bind(&BackDDSViewFactory::receivedTopicDeposit, this, std::placeholders::_1))),
    m_readerWithdraw(createDataReader<Withdraw>(WITHDRAW_TOPIC, std::bind(&BackDDSViewFactory::receivedTopicWithdraw, this, std::placeholders::_1))),
    m_readerTransaction(createDataReader<Transaction>(TRANSACTION_TOPIC, std::bind(&BackDDSViewFactory::receivedTopicTransaction, this, std::placeholders::_1))),
    m_writerSelectFundAck(createrDataWriter<SelectFundAck>(SELECT_FUND_TOPIC_ACK)),
    m_writerFundData(createrDataWriter<FundData>(FUND_DATA_TOPIC))
{
    utils::so::setup_signal_handlers();

    m_threadsForReading[SELECT_FUND_TOPIC] = initReadingTopicThread(&BackDDSViewFactory::readingTopicSelectFund);
    m_threadsForReading[DEPOSIT_TOPIC] = initReadingTopicThread(&BackDDSViewFactory::readingTopicDeposit);
    m_threadsForReading[WITHDRAW_TOPIC] = initReadingTopicThread(&BackDDSViewFactory::readingTopicWithdraw);
    m_threadsForReading[TRANSACTION_TOPIC] = initReadingTopicThread(&BackDDSViewFactory::readingTopicTransaction);
}

void BackDDSViewFactory::readingTopicSelectFund()
{
    while(!utils::so::shutdown_requested)
    {
        m_readerSelectFund.wait(m_wait);
    }
}

void BackDDSViewFactory::readingTopicDeposit()
{
    while(!utils::so::shutdown_requested)
    {
        m_readerDeposit.wait(m_wait);
    }
}

void BackDDSViewFactory::readingTopicWithdraw()
{
    while(!utils::so::shutdown_requested)
    {
        m_readerWithdraw.wait(m_wait);
    }
}

void BackDDSViewFactory::readingTopicTransaction()
{
    while(!utils::so::shutdown_requested)
    {
        m_readerTransaction.wait(m_wait);
    }
}

std::thread BackDDSViewFactory::initReadingTopicThread(void (backend::view::dds::operations::BackDDSViewFactory::*function)())
{
    return std::thread(function, this);
}

}
}
}
}
