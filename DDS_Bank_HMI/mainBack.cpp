#include <iostream>

#include <model/source/operations/AllFunds.hpp>
#include <model/source/visualization/message/AllMessages.hpp>
#include <backend/source/controller/operations/SelectFundController.hpp>
#include <backend/source/controller/operations/DepositMoneyController.hpp>
#include <backend/source/controller/operations/WithdrawMoneyController.hpp>
#include <backend/source/controller/operations/TransferMoneyController.hpp>
#include <backend/source/controller/visualization/ShowMessageController.hpp>
#include <backend/source/view/dds/operations/BackDDSView.hpp>
#include <backend/source/view/dds/visualization/BackDDSView.hpp>
#include <backend/source/view/includeView/visualization/ShowMessageIncludeView.hpp>

using SelectFundController = backend::controller::operations::SelectFundController;
using DepositMoneyController = backend::controller::operations::DepositMoneyController;
using WithdrawMoneyController = backend::controller::operations::WithdrawMoneyController;
using TransferMoneyController = backend::controller::operations::TransferMoneyController;
using ShowMessageController = backend::controller::visualization::ShowMessageController;
using ShowMessageIncludeView = backend::view::includeView::visualization::ShowMessageIncludeView;

int main(int argc, char *argv[])
{
    std::shared_ptr<model::operations::AllFunds> allFunds (new model::operations::AllFunds(model::operations::kFundType::Savings));
    std::shared_ptr<model::visualization::message::AllMessages> allMessages(new model::visualization::message::AllMessages());

    std::shared_ptr<SelectFundController> selectFundController(new SelectFundController(allFunds));
    std::shared_ptr<DepositMoneyController> depositMoneyController(new DepositMoneyController(allFunds, allFunds));
    std::shared_ptr<WithdrawMoneyController> withdrawMoneyController(new WithdrawMoneyController(allFunds, allFunds));
    std::shared_ptr<TransferMoneyController> transferMoneyController(new TransferMoneyController(allFunds, allFunds));
    std::shared_ptr<ShowMessageController> showMessageController(new ShowMessageController(allMessages));

    std::shared_ptr<backend::view::dds::operations::BackDDSView>backDDSViewOperations(
                new backend::view::dds::operations::BackDDSView(
                    0,2,
                    selectFundController,
                    depositMoneyController,
                    withdrawMoneyController,
                    transferMoneyController));
    std::shared_ptr<backend::view::dds::visualization::BackDDSView> backDDSViewVisualization(
                new backend::view::dds::visualization::BackDDSView(0, 2));
    std::shared_ptr<ShowMessageIncludeView> showMessageIncludeView(new ShowMessageIncludeView(showMessageController));

    allFunds->utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFund>::addSubscriber(backDDSViewOperations);
    allFunds->utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFundType>::addSubscriber(backDDSViewOperations);

    depositMoneyController->addSubscriber(showMessageIncludeView);
    withdrawMoneyController->addSubscriber(showMessageIncludeView);
    transferMoneyController->addSubscriber(showMessageIncludeView);
    allMessages->addSubscriber(backDDSViewVisualization);

    while(true)
    {
        int i = 0;
    }
    return 0;
}
