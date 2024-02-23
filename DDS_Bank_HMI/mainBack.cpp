#include <iostream>
#include <memory>

#include <backend/source/controller/operations/DepositMoney.hpp>
#include <backend/source/controller/operations/SelectFund.hpp>
#include <backend/source/controller/operations/TransferMoney.hpp>
#include <backend/source/controller/operations/WithdrawMoney.hpp>
#include <backend/source/controller/visualization/ShowMessage.hpp>
#include <backend/source/view/dds/operations/BackDDSView.hpp>
#include <backend/source/view/dds/visualization/BackDDSView.hpp>
#include <backend/source/view/includeView/visualization/ShowMessage.hpp>
#include <model/source/operations/AllFunds.hpp>
#include <model/source/visualization/message/AllMessages.hpp>

using SelectFundController = backend::controller::operations::SelectFund;
using DepositMoneyController = backend::controller::operations::DepositMoney;
using WithdrawMoneyController = backend::controller::operations::WithdrawMoney;
using TransferMoneyController = backend::controller::operations::TransferMoney;
using ShowMessageController = backend::controller::visualization::ShowMessage;
using ShowMessageIncludeView = backend::view::includeView::visualization::ShowMessage;

int main(int argc, char *argv[])
{
  std::shared_ptr<model::operations::AllFunds> allFunds =
      std::make_shared<model::operations::AllFunds>(model::operations::kFundType::Savings);
  std::shared_ptr<model::visualization::message::AllMessages> allMessages =
      std::make_shared<model::visualization::message::AllMessages>();

  std::shared_ptr<SelectFundController> selectFundController =
      std::make_shared<SelectFundController>(allFunds);
  std::shared_ptr<DepositMoneyController> depositMoneyController =
      std::make_shared<DepositMoneyController>(allFunds, allFunds);
  std::shared_ptr<WithdrawMoneyController> withdrawMoneyController =
      std::make_shared<WithdrawMoneyController>(allFunds, allFunds);
  std::shared_ptr<TransferMoneyController> transferMoneyController =
      std::make_shared<TransferMoneyController>(allFunds, allFunds);
  std::shared_ptr<ShowMessageController> showMessageController =
      std::make_shared<ShowMessageController>(allMessages);

  std::shared_ptr<backend::view::dds::operations::BackDDSView> backDDSViewOperations =
      std::make_shared<backend::view::dds::operations::BackDDSView>(0, 2, selectFundController,
                                                                    depositMoneyController,
                                                                    withdrawMoneyController,
                                                                    transferMoneyController);
  std::shared_ptr<backend::view::dds::visualization::BackDDSView> backDDSViewVisualization =
      std::make_shared<backend::view::dds::visualization::BackDDSView>(0, 2);
  std::shared_ptr<ShowMessageIncludeView> showMessageIncludeView =
      std::make_shared<ShowMessageIncludeView>(showMessageController);

  allFunds->utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFund>::addSubscriber(
        backDDSViewOperations);
  allFunds->utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFundType>::addSubscriber(
        backDDSViewOperations);

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
