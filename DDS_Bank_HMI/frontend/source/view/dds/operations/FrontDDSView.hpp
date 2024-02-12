#ifndef FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEW_HPP
#define FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEW_HPP

#include <iostream>

#include <idl/bank.hpp>

#include <utils/source/designPattern/SignalSubscriber.hpp>
#include <frontend/source/view/dds/operations/FrontDDSViewFactory.hpp>
#include <frontend/source/viewModel/dds/operations/DDSViewModel.hpp>
#include <frontend/source/viewModel/ui/operations/signal/DepositMoneySignal.hpp>
#include <frontend/source/viewModel/ui/operations/signal/TransferedMoneySignal.hpp>
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
        public frontend::view::dds::operations::FrontDDSViewFactory,
        public utils::designPattern::SignalSubscriber<frontend::viewModel::ui::operations::signal::SelectFundSignal>,
        public utils::designPattern::SignalSubscriber<frontend::viewModel::ui::operations::signal::DepositMoneySignal>,
        public utils::designPattern::SignalSubscriber<frontend::viewModel::ui::operations::signal::WithdrawnMoneySignal>,
        public utils::designPattern::SignalSubscriber<frontend::viewModel::ui::operations::signal::TransferedMoneySignal>
{
    public:
        FrontDDSView(unsigned int domainId,
                     unsigned int sampleCount,
                     std::shared_ptr<frontend::viewModel::dds::operations::DDSViewModel> ddsViewModel);

        void recievedSignal(frontend::viewModel::ui::operations::signal::SelectFundSignal signal) override;
        void recievedSignal(frontend::viewModel::ui::operations::signal::DepositMoneySignal signal) override;
        void recievedSignal(frontend::viewModel::ui::operations::signal::WithdrawnMoneySignal signal) override;
        void recievedSignal(frontend::viewModel::ui::operations::signal::TransferedMoneySignal signal) override;

    private:
        void writeSelectFund(FundType fundType);
        void writeDeposit(int16_t amount);
        void writeWithdraw(int16_t amount);
        void writeTransaction(const FundType& destinationFundType, int16_t amount);

        void receivedTopicSelectFundAck(SelectFundAck selectFundAck) override;
        void receivedTopicFundData(FundData fundData) override;

        std::shared_ptr<frontend::viewModel::dds::operations::DDSViewModel> m_ddsviewModel;


};

}
}
}
}

#endif // FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEW_HPP
