#include "CommunicationFactory.hpp"

namespace frontend
{
namespace view
{
namespace dds
{
namespace operations
{

CommunicationFactory::CommunicationFactory(unsigned int domainId, unsigned int sampleCount) :
  utils::dds::DDSView(domainId, sampleCount),
  mWriterSelectFund(createrDataWriter<SelectFund>(SELECT_FUND_TOPIC)),
  mWriterDeposit(createrDataWriter<Deposit>(DEPOSIT_TOPIC)),
  mWriterWithdraw(createrDataWriter<Withdraw>(WITHDRAW_TOPIC)),
  mWriterTransfer(createrDataWriter<Transaction>(TRANSACTION_TOPIC)),
  mReaderSelectFundAck(
    createDataReader<SelectFundAck>(
      SELECT_FUND_TOPIC_ACK, std::bind(
        &CommunicationFactory::receivedTopicSelectFundAck, this, std::placeholders::_1))),
  mReaderFundData(
    createDataReader<FundData>(
      FUND_DATA_TOPIC, std::bind(&CommunicationFactory::receivedTopicFundData, this, std::placeholders::_1)))
{
  utils::so::setupSignalHandlers();

  mThreadsForReading[SELECT_FUND_TOPIC_ACK] =
      initReadingTopicThread(&CommunicationFactory::readingTopicSelectFundAck);
  mThreadsForReading[FUND_DATA_TOPIC] =
      initReadingTopicThread(&CommunicationFactory::readingTopicFundData);
}

void CommunicationFactory::readingTopicFundData()
{
  while(!utils::so::shutdownRequested)
  {
    mReaderFundData.wait(mWait);
  }
}

void CommunicationFactory::readingTopicSelectFundAck()
{
  while(!utils::so::shutdownRequested)
  {
    mReaderSelectFundAck.wait(mWait);
  }
}

std::thread CommunicationFactory::initReadingTopicThread(
    void (frontend::view::dds::operations::CommunicationFactory::*function)())
{
  return std::thread(function, this);
}

}  // namespace operations
}  // namespace dds
}  // namespace view
}  // namespace frontend
