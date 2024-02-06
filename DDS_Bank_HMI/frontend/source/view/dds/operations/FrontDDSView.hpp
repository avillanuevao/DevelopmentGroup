#ifndef FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEW_HPP
#define FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEW_HPP

#include <iostream>
#include <thread>

#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include <rti/util/util.hpp>
#include <rti/config/Logger.hpp>

#include <idl/bank.hpp>
#include <utils/source/dds/DDSView.hpp>
#include <utils/source/dds/DDSDataWriter.hpp>
#include <utils/source/dds/DDSDataReader.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>
#include <frontend/source/viewModel/dds/operations/DDSViewModel.hpp>
#include <frontend/source/viewModel/signal/DepositMoneySignal.hpp>
#include <frontend/source/viewModel/signal/TransferedMoneySignal.hpp>
#include <frontend/source/viewModel/ui/operations/signal/SelectFundSignal.hpp>
#include <frontend/source/viewModel/ui/operations/signal/WithdrawnMoneySignal.hpp>

namespace frontend
{
namespace view
{
namespace dds
{
namespace operations
{
class FrontDDSView :
        public utils::dds::DDSView,
        public utils::designPattern::SignalSubscriber<frontend::viewModel::ui::operations::signal::SelectFundSignal>,
        public utils::designPattern::SignalSubscriber<viewModel::signal::DepositMoneySignal>,
        public utils::designPattern::SignalSubscriber<frontend::viewModel::ui::operations::signal::WithdrawnMoneySignal>,
        public utils::designPattern::SignalSubscriber<frontend::viewModel::signal::TransferedMoneySignal>
{
    public:
        FrontDDSView(unsigned int domainId,
                     unsigned int sampleCount,
                     std::shared_ptr<frontend::viewModel::dds::operations::DDSViewModel> ddsViewModel);

        void update(frontend::viewModel::ui::operations::signal::SelectFundSignal signal);
        void update(frontend::viewModel::signal::DepositMoneySignal signal);
        void update(frontend::viewModel::ui::operations::signal::WithdrawnMoneySignal signal);
        void update(frontend::viewModel::signal::TransferedMoneySignal signal);

    private:
        void writeSelectFund(FundType fundType);
        void writeDeposit(int16_t amount);
        void writeWithdraw(int16_t amount);
        const Transaction writeTransaction(const FundType& originFundType, const FundType& destinationFundType, int16_t amount);

        void receivedTopicSelectFundAck(SelectFundAck selectFundAck);
        void readingTopicSelectFundAck();
        void receivedTopicFundData(FundData fundData);
        void readingTopicFundData();

        std::thread initReadingTopicThread(void (frontend::view::dds::operations::FrontDDSView::*function)());

        std::shared_ptr<frontend::viewModel::dds::operations::DDSViewModel> m_ddsViewModel;

        utils::dds::DDSDataWriter<SelectFund> m_writerSelectFund;
        utils::dds::DDSDataWriter<Deposit> m_writerDeposit;
        utils::dds::DDSDataWriter<Withdraw> m_writerWithdraw;
//        utils::dds::DDSDataWriter<Transaction> m_writerTransfer;
        utils::dds::DDSDataReader<SelectFundAck> m_readerSelectFundAck;
        utils::dds::DDSDataReader<FundData> m_readerFundData;
};

}
}
}
}

#endif // FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEW_HPP
