#include <iostream>
#include <memory>

#include <backend/source/controller/operations/DepositMoney.hpp>
#include <backend/source/controller/operations/SaveFund.hpp>
#include <backend/source/controller/operations/SelectFund.hpp>
#include <backend/source/controller/operations/TransferMoney.hpp>
#include <backend/source/controller/operations/WithdrawMoney.hpp>
#include <backend/source/controller/operations/signal/SaveFund.hpp>
#include <backend/source/controller/operations/signal/ShowMessage.hpp>
#include <backend/source/controller/visualization/ShowMessage.hpp>
#include <backend/source/view/dds/operations/Communication.hpp>
#include <backend/source/view/dds/visualization/Communication.hpp>
#include <backend/source/view/includeView/operations/SaveFund.hpp>
#include <backend/source/view/includeView/visualization/ShowMessage.hpp>
#include <model/source/operations/AllFunds.hpp>
#include <model/source/visualization/message/AllMessages.hpp>

using DepositMoneyController = backend::controller::operations::DepositMoney;
using SaveFundController = backend::controller::operations::SaveFund;
using SelectFundController = backend::controller::operations::SelectFund;
using TransferMoneyController = backend::controller::operations::TransferMoney;
using WithdrawMoneyController = backend::controller::operations::WithdrawMoney;
using ShowMessageController = backend::controller::visualization::ShowMessage;
using CommunicationOperations = backend::view::dds::operations::Communication;
using CommunicationVisualization = backend::view::dds::visualization::Communication;
using SaveFundIncludeView = backend::view::includeView::operations::SaveFund;
using ShowMessageIncludeView = backend::view::includeView::visualization::ShowMessage;
using ShowMessageSignal = backend::controller::operations::signal::ShowMessage;
using SaveFundSignal = backend::controller::operations::signal::SaveFund;
using ShowMessageSignalPublisher = utils::designPattern::SignalPublisher<ShowMessageSignal>;
using SaveFundSignalPublisher = utils::designPattern::SignalPublisher<SaveFundSignal>;

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
  std::shared_ptr<SaveFundController> saveFundController = std::make_shared<SaveFundController>(allFunds);

  std::shared_ptr<CommunicationOperations> communicationOperations =
      std::make_shared<CommunicationOperations>(0, 2, selectFundController,depositMoneyController,
                                                withdrawMoneyController,transferMoneyController);
  std::shared_ptr<CommunicationVisualization> communicationVisualization =
      std::make_shared<CommunicationVisualization>(0, 2);
  std::shared_ptr<ShowMessageIncludeView> showMessageIncludeView =
      std::make_shared<ShowMessageIncludeView>(showMessageController);
  std::shared_ptr<SaveFundIncludeView> saveFundIncludeView =
      std::make_shared<SaveFundIncludeView>(saveFundController);

  allFunds->utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFund>::addSubscriber(
        communicationOperations);
  allFunds->utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFundType>::addSubscriber(
        communicationOperations);

  allMessages->addSubscriber(communicationVisualization);

  depositMoneyController->ShowMessageSignalPublisher::addSubscriber(showMessageIncludeView);
  depositMoneyController->SaveFundSignalPublisher::addSubscriber(saveFundIncludeView);
  withdrawMoneyController->ShowMessageSignalPublisher::addSubscriber(showMessageIncludeView);
  withdrawMoneyController->SaveFundSignalPublisher::addSubscriber(saveFundIncludeView);
  transferMoneyController->ShowMessageSignalPublisher::addSubscriber(showMessageIncludeView);
  transferMoneyController->SaveFundSignalPublisher::addSubscriber(saveFundIncludeView);

  while(true)
  {
    int i = 0;
  }
  return 0;
}
