#ifndef FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEW_HPP
#define FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEW_HPP

#include <iostream>

#include <frontend/source/view/dds/operations/FrontDDSViewFactory.hpp>
#include <frontend/source/viewModel/dds/operations/DDSViewModel.hpp>
#include <frontend/source/viewModel/ui/operations/signal/DepositMoney.hpp>
#include <frontend/source/viewModel/ui/operations/signal/SelectFund.hpp>
#include <frontend/source/viewModel/ui/operations/signal/TransferedMoney.hpp>
#include <frontend/source/viewModel/ui/operations/signal/WithdrawnMoney.hpp>
#include <idl/bank.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>

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
    public utils::designPattern::SignalSubscriber<frontend::viewModel::ui::operations::signal::DepositMoney>,
    public utils::designPattern::SignalSubscriber<frontend::viewModel::ui::operations::signal::SelectFund>,
    public utils::designPattern::SignalSubscriber<frontend::viewModel::ui::operations::signal::TransferedMoney>,
    public utils::designPattern::SignalSubscriber<frontend::viewModel::ui::operations::signal::WithdrawnMoney>
{
  public:
    FrontDDSView(unsigned int domainId, unsigned int sampleCount,
                 std::shared_ptr<frontend::viewModel::dds::operations::DDSViewModel> ddsViewModel);

    void recievedSignal(frontend::viewModel::ui::operations::signal::DepositMoney signal) override;
    void recievedSignal(frontend::viewModel::ui::operations::signal::SelectFund signal) override;
    void recievedSignal(frontend::viewModel::ui::operations::signal::TransferedMoney signal) override;
    void recievedSignal(frontend::viewModel::ui::operations::signal::WithdrawnMoney signal) override;

  private:
    void receivedTopicFundData(FundData fundData) override;
    void receivedTopicSelectFundAck(SelectFundAck selectFundAck) override;

    void writeDeposit(int16_t amount);
    void writeSelectFund(FundType fundType);
    void writeTransaction(const FundType& destinationFundType, int16_t amount);
    void writeWithdraw(int16_t amount);

    std::shared_ptr<frontend::viewModel::dds::operations::DDSViewModel> mDDSviewModel;
};

}  // namespace operations
}  // namespace dds
}  // namespace view
}  // namespace frontend

#endif  // FRONTEND_VIEW_DDS_OPERATIONS_FRONTDDSVIEW_HPP
