#ifndef BACKEND_VIEW_DDS_OPERATIONS_BACKDDSVIEWFACTORY_HPP
#define BACKEND_VIEW_DDS_OPERATIONS_BACKDDSVIEWFACTORY_HPP

#include <idl/bank.hpp>

#include <dds/DDSDataReader.hpp>
#include <dds/DDSDataWriter.hpp>
#include <dds/DDSView.hpp>

namespace backend
{
namespace view
{
namespace dds
{
namespace operations
{

class BackDDSViewFactory :
    protected utils::dds::DDSView
{
  public:
    BackDDSViewFactory(unsigned int domainId, unsigned int sampleCount);

  protected:
    virtual void receivedTopicSelectFund(SelectFund selectFund) = 0;
    virtual void receivedTopicDeposit(Deposit deposit) = 0;
    virtual void receivedTopicWithdraw(Withdraw withdraw) = 0;
    virtual void receivedTopicTransaction(Transaction transaction) = 0;

    void readingTopicSelectFund();
    void readingTopicDeposit();
    void readingTopicWithdraw();
    void readingTopicTransaction();

    utils::dds::DDSDataReader<SelectFund> mReaderSelectFund;
    utils::dds::DDSDataReader<Deposit> mReaderDeposit;
    utils::dds::DDSDataReader<Withdraw> mReaderWithdraw;
    utils::dds::DDSDataReader<Transaction> mReaderTransaction;
    utils::dds::DDSDataWriter<SelectFundAck> mWriterSelectFundAck;
    utils::dds::DDSDataWriter<FundData> mWriterFundData;

  private:
    std::thread initReadingTopicThread(void (backend::view::dds::operations::BackDDSViewFactory::*function)());

};

}  // namespace operations
}  // namespace dds
}  // namespace view
}  // namespace backend

#endif // BACKEND_VIEW_DDS_OPERATIONS_BACKDDSVIEWFACTORY_HPP
