#include "CommunicationFactory.hpp"

namespace backend
{
namespace view
{
namespace dds
{
namespace operations
{

CommunicationFactory::CommunicationFactory(unsigned int domainId, unsigned int sampleCount) :
  utils::dds::DDSView(domainId, sampleCount),
  mReaderSelectFund(createDataReader<SelectFund>(SELECT_FUND_TOPIC, std::bind(
                                                   &CommunicationFactory::receivedTopicSelectFund, this,
                                                   std::placeholders::_1))),
  mReaderDeposit(createDataReader<Deposit>(DEPOSIT_TOPIC, std::bind(
                                             &CommunicationFactory::receivedTopicDeposit, this,
                                             std::placeholders::_1))),
  mReaderWithdraw(createDataReader<Withdraw>(WITHDRAW_TOPIC, std::bind(
                                               &CommunicationFactory::receivedTopicWithdraw, this,
                                               std::placeholders::_1))),
  mReaderTransaction(createDataReader<Transaction>(TRANSACTION_TOPIC, std::bind(
                                                     &CommunicationFactory::receivedTopicTransaction, this,
                                                     std::placeholders::_1))),
  mWriterSelectFundAck(createrDataWriter<SelectFundAck>(SELECT_FUND_TOPIC_ACK)),
  mWriterFundData(createrDataWriter<FundData>(FUND_DATA_TOPIC))
{
  utils::so::setupSignalHandlers();

  mThreadsForReading[SELECT_FUND_TOPIC] =
      initReadingTopicThread(&CommunicationFactory::readingTopicSelectFund);
  mThreadsForReading[DEPOSIT_TOPIC] = initReadingTopicThread(&CommunicationFactory::readingTopicDeposit);
  mThreadsForReading[WITHDRAW_TOPIC] = initReadingTopicThread(&CommunicationFactory::readingTopicWithdraw);
  mThreadsForReading[TRANSACTION_TOPIC] =
      initReadingTopicThread(&CommunicationFactory::readingTopicTransaction);
}

void CommunicationFactory::readingTopicSelectFund()
{
  while(!utils::so::shutdownRequested)
  {
    mReaderSelectFund.wait(mWait);
  }
}

void CommunicationFactory::readingTopicDeposit()
{
  while(!utils::so::shutdownRequested)
  {
    mReaderDeposit.wait(mWait);
  }
}

void CommunicationFactory::readingTopicWithdraw()
{
  while(!utils::so::shutdownRequested)
  {
    mReaderWithdraw.wait(mWait);
  }
}

void CommunicationFactory::readingTopicTransaction()
{
  while(!utils::so::shutdownRequested)
  {
    mReaderTransaction.wait(mWait);
  }
}

std::thread CommunicationFactory::initReadingTopicThread(
    void (backend::view::dds::operations::CommunicationFactory::*function)())
{
  return std::thread(function, this);
}

}  // namespace operations
}  // namespace dds
}  // namespace view
}  // namespace backend
