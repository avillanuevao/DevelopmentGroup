#ifndef FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEWFACTORY_HPP
#define FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEWFACTORY_HPP

#include <thread>

#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include <rti/config/Logger.hpp>
#include <rti/util/util.hpp>

#include <idl/bank.hpp>
#include <utils/source/dds/DDSDataReader.hpp>
#include <utils/source/dds/DDSDataWriter.hpp>
#include <utils/source/dds/DDSView.hpp>

namespace frontend
{
namespace view
{
namespace dds
{
namespace operations
{

class FrontDDSViewFactory :
    public utils::dds::DDSView

{
  public:
    FrontDDSViewFactory(unsigned int domainId, unsigned int sampleCount);

  protected:
    virtual void receivedTopicSelectFundAck(SelectFundAck selectFundAck) = 0;
    virtual void receivedTopicFundData(FundData fundData) = 0;

    utils::dds::DDSDataWriter<SelectFund> mWriterSelectFund;
    utils::dds::DDSDataWriter<Deposit> mWriterDeposit;
    utils::dds::DDSDataWriter<Withdraw> mWriterWithdraw;
    utils::dds::DDSDataWriter<Transaction> mWriterTransfer;
    utils::dds::DDSDataReader<SelectFundAck> mReaderSelectFundAck;
    utils::dds::DDSDataReader<FundData> mReaderFundData;

  private:
    void readingTopicFundData();
    void readingTopicSelectFundAck();
    std::thread initReadingTopicThread(
        void (frontend::view::dds::operations::FrontDDSViewFactory::*function)());


};

}  // namespace operations
}  // namespace dds
}  // namespace view
}  // namespace frontend

#endif  // FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEWFACTORY_HPP
