#ifndef FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEWFACTORY_HPP
#define FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEWFACTORY_HPP

#include <thread>

#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include <rti/util/util.hpp>
#include <rti/config/Logger.hpp>

#include <idl/bank.hpp>
#include <utils/source/dds/DDSView.hpp>
#include <utils/source/dds/DDSDataWriter.hpp>
#include <utils/source/dds/DDSDataReader.hpp>

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
        FrontDDSViewFactory(unsigned int domainId,
                            unsigned int sampleCount);

    protected:
        virtual void receivedTopicSelectFundAck(SelectFundAck selectFundAck) = 0;
        virtual void receivedTopicFundData(FundData fundData) = 0;

        utils::dds::DDSDataWriter<SelectFund> m_writerSelectFund;
        utils::dds::DDSDataWriter<Deposit> m_writerDeposit;
        utils::dds::DDSDataWriter<Withdraw> m_writerWithdraw;
        utils::dds::DDSDataWriter<Transaction> m_writerTransfer;
        utils::dds::DDSDataReader<SelectFundAck> m_readerSelectFundAck;
        utils::dds::DDSDataReader<FundData> m_readerFundData;

    private:
        void readingTopicSelectFundAck();
        void readingTopicFundData();
        std::thread initReadingTopicThread(void (frontend::view::dds::operations::FrontDDSViewFactory::*function)());


};

}
}
}
}


#endif // FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEWFACTORY_HPP
