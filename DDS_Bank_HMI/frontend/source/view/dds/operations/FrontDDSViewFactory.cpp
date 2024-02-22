#include "FrontDDSViewFactory.hpp"

namespace frontend
{
namespace view
{
namespace dds
{
namespace operations
{

FrontDDSViewFactory::FrontDDSViewFactory(unsigned int domainId, unsigned int sampleCount) :
    utils::dds::DDSView(domainId, sampleCount),
    m_writerSelectFund(createrDataWriter<SelectFund>(SELECT_FUND_TOPIC)),
    m_writerDeposit(createrDataWriter<Deposit>(DEPOSIT_TOPIC)),
    m_writerWithdraw(createrDataWriter<Withdraw>(WITHDRAW_TOPIC)),
    m_writerTransfer(createrDataWriter<Transaction>(TRANSACTION_TOPIC)),
    m_readerSelectFundAck(createDataReader<SelectFundAck>(SELECT_FUND_TOPIC_ACK, std::bind(&FrontDDSViewFactory::receivedTopicSelectFundAck, this, std::placeholders::_1))),
    m_readerFundData(createDataReader<FundData>(FUND_DATA_TOPIC, std::bind(&FrontDDSViewFactory::receivedTopicFundData, this, std::placeholders::_1)))

{
    utils::so::setupSignalHandlers();

    mThreadsForReading[SELECT_FUND_TOPIC_ACK] = initReadingTopicThread(&FrontDDSViewFactory::readingTopicSelectFundAck);
    mThreadsForReading[FUND_DATA_TOPIC] = initReadingTopicThread(&FrontDDSViewFactory::readingTopicFundData);

}

void FrontDDSViewFactory::readingTopicFundData()
{
    while(!utils::so::shutdownRequested)
    {
        m_readerFundData.wait(mWait);
    }
}

void FrontDDSViewFactory::readingTopicSelectFundAck()
{
    while(!utils::so::shutdownRequested)
    {
        m_readerSelectFundAck.wait(mWait);
    }
}

std::thread FrontDDSViewFactory::initReadingTopicThread(void (frontend::view::dds::operations::FrontDDSViewFactory::*function)())
{
    return std::thread(function, this);
}


}
}
}
}
