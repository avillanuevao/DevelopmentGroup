#ifndef BACKEND_VIEW_DDS_OPERATIONS_BACKDDSVIEWFACTORY_HPP
#define BACKEND_VIEW_DDS_OPERATIONS_BACKDDSVIEWFACTORY_HPP

#include <idl/bank.hpp>
#include <dds/DDSView.hpp>
#include <dds/DDSDataReader.hpp>
#include <dds/DDSDataWriter.hpp>

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
        BackDDSViewFactory(unsigned int domainId,
                           unsigned int sampleCount);

    protected:
        virtual void receivedTopicSelectFund(SelectFund selectFund) = 0;
        virtual void receivedTopicDeposit(Deposit deposit) = 0;
        virtual void receivedTopicWithdraw(Withdraw withdraw) = 0;
        virtual void receivedTopicTransaction(Transaction transaction) = 0;
        void readingTopicSelectFund();
        void readingTopicDeposit();
        void readingTopicWithdraw();
        void readingTopicTransaction();


        utils::dds::DDSDataReader<SelectFund> m_readerSelectFund;
        utils::dds::DDSDataReader<Deposit> m_readerDeposit;
        utils::dds::DDSDataReader<Withdraw> m_readerWithdraw;
        utils::dds::DDSDataReader<Transaction> m_readerTransaction;
        utils::dds::DDSDataWriter<SelectFundAck> m_writerSelectFundAck;
        utils::dds::DDSDataWriter<FundData> m_writerFundData;

    private:
        std::thread initReadingTopicThread(void (backend::view::dds::operations::BackDDSViewFactory::*function)());

};

}
}
}
}


#endif // BACKEND_VIEW_DDS_OPERATIONS_BACKDDSVIEWFACTORY_HPP
