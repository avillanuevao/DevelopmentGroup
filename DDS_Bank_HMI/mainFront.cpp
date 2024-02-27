#include <memory>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <model/source/operations/AllFunds.hpp>
#include <model/source/visualization/language/AllLanguages.hpp>
#include <model/source/visualization/message/AllMessages.hpp>
#include <model/source/visualization/language/kLiterals.hpp>
#include <view/dds/operations/Communication.hpp>
#include <view/dds/visualization/Communication.hpp>
#include <view/includeView/visualization/VisualizeFund.hpp>
#include <view/includeView/visualization/Visualize.hpp>
#include <view/ui/operations/DepositMoney.hpp>
#include <view/ui/operations/SelectFund.hpp>
#include <view/ui/operations/TransferMoney.hpp>
#include <view/ui/operations/WithdrawMoney.hpp>
#include <view/ui/visualization/ShowMessage.hpp>
#include <view/ui/visualization/VisualizeFund.hpp>
#include <view/ui/visualization/Visualize.hpp>
#include <viewModel/dds/operations/Communication.hpp>
#include <viewModel/dds/visualization/Communication.hpp>
#include <viewModel/ui/operations/Deposit.hpp>
#include <viewModel/ui/operations/SelectFund.hpp>
#include <viewModel/ui/operations/Transfer.hpp>
#include <viewModel/ui/operations/Withdraw.hpp>
#include <viewModel/ui/visualization/ShowMessage.hpp>
#include <viewModel/ui/visualization/VisualizeFund.hpp>
#include <viewModel/ui/visualization/Visualize.hpp>

using CommunicationOperations = frontend::view::dds::operations::Communication;
using CommunicationVisualization = frontend::view::dds::visualization::Communication;
using VisualizeFundIncludeView = frontend::view::includeView::visualization::VisualizeFund;
using VisualizeIncludeView = frontend::view::includeView::visualization::Visualize;
using DepositMoneyView = frontend::view::ui::operations::DepositMoney;
using SelectFundView = frontend::view::ui::operations::SelectFund;
using TransferMoneyView = frontend::view::ui::operations::TransferMoney;
using WithdrawMoneyView = frontend::view::ui::operations::WithdrawMoney;
using VisualizeFundView = frontend::view::ui::visualization::VisualizeFund;
using VisualizeView = frontend::view::ui::visualization::Visualize;
using ShowMessageView = frontend::view::ui::visualization::ShowMessage;
using DDSViewModelOperations = frontend::viewModel::dds::operations::Communication;
using DDSViewModelVisualization = frontend::viewModel::dds::visualization::Communication;
using DepositViewModel = frontend::viewModel::ui::operations::Deposit;
using SelectFundViewModel = frontend::viewModel::ui::operations::SelectFund;
using TransferViewModel = frontend::viewModel::ui::operations::Transfer;
using WithdrawViewModel = frontend::viewModel::ui::operations::Withdraw;
using ShowMessageViewModel = frontend::viewModel::ui::visualization::ShowMessage;
using VisualizeFundViewModel = frontend::viewModel::ui::visualization::VisualizeFund;
using VisualizeViewModel = frontend::viewModel::ui::visualization::Visualize;

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  std::shared_ptr<model::operations::AllFunds> allFunds =
      std::make_shared<model::operations::AllFunds>(model::operations::kFundType::Savings);
  std::shared_ptr<model::visualization::message::AllMessages> allMessage =
      std::make_shared<model::visualization::message::AllMessages>();
  std::shared_ptr<model::visualization::language::AllLanguages> allLanguages =
        std::make_shared<model::visualization::language::AllLanguages>(
          model::visualization::language::kLanguagesAvailables::Spanish);

  std::shared_ptr<DepositViewModel> depositViewModel = std::make_shared<DepositViewModel>();
  std::shared_ptr<WithdrawViewModel> withdrawViewModel = std::make_shared<WithdrawViewModel>();
  std::shared_ptr<DDSViewModelOperations> ddsViewModelOperations =
      std::make_shared<DDSViewModelOperations>(allFunds, allFunds);
  std::shared_ptr<DDSViewModelVisualization> ddsViewModelVisualization =
      std::make_shared<DDSViewModelVisualization>(allMessage);
  std::shared_ptr<VisualizeFundViewModel> visualizeFundViewModel =
      std::make_shared<VisualizeFundViewModel>(allFunds);
  std::shared_ptr<VisualizeViewModel> visualizeViewModel =
      std::make_shared<VisualizeViewModel>();
  std::shared_ptr<SelectFundViewModel> selectFundViewModel = std::make_shared<SelectFundViewModel>();
  std::shared_ptr<TransferViewModel> transferViewModel = std::make_shared<TransferViewModel>();
  std::shared_ptr<ShowMessageViewModel> showMessageViewModel = std::make_shared<ShowMessageViewModel>();

  std::shared_ptr<DepositMoneyView> depositMoneyView =
      std::make_shared<DepositMoneyView>(depositViewModel, engine);
  std::shared_ptr<WithdrawMoneyView> withdrawMoneyView =
      std::make_shared<WithdrawMoneyView>(withdrawViewModel, engine);
  std::shared_ptr<CommunicationOperations> communicationOperations =
      std::make_shared<CommunicationOperations>(0, 2, ddsViewModelOperations);
  std::shared_ptr<CommunicationVisualization> communicationVisualization =
      std::make_shared<CommunicationVisualization>(0, 2, ddsViewModelVisualization);
  std::shared_ptr<VisualizeFundIncludeView> visualizeFundIncludeView =
      std::make_shared<VisualizeFundIncludeView>(visualizeFundViewModel);
  std::shared_ptr<VisualizeIncludeView> visualizeIncludeView =
      std::make_shared<VisualizeIncludeView>(visualizeViewModel);
  std::shared_ptr<VisualizeFundView> visualizeFundView = std::make_shared<VisualizeFundView>(engine);
  std::shared_ptr<VisualizeView> visualizeView = std::make_shared<VisualizeView>(allLanguages, engine);
  std::shared_ptr<SelectFundView> selectFundView =
      std::make_shared<SelectFundView>(selectFundViewModel, engine);
  std::shared_ptr<TransferMoneyView> transferMoneyView =
      std::make_shared<TransferMoneyView>(transferViewModel, engine);
  std::shared_ptr<ShowMessageView> showMessageView = std::make_shared<ShowMessageView>(allLanguages, engine);

  allFunds->utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFundType>::
      addSubscriber(visualizeFundIncludeView);
  allFunds->utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFund>::
      addSubscriber(visualizeFundIncludeView);

  allMessage->addSubscriber(showMessageViewModel);

  allLanguages->addSubscriber(visualizeIncludeView);

  depositViewModel->addSubscriber(communicationOperations);
  withdrawViewModel->addSubscriber(communicationOperations);
  visualizeFundViewModel->addSubscriber(visualizeFundView);
  selectFundViewModel->addSubscriber(communicationOperations);
  transferViewModel->addSubscriber(communicationOperations);
  showMessageViewModel->addSubscriber(showMessageView);
  visualizeViewModel->addSubscriber(visualizeView);

  allLanguages->setLanguage(model::visualization::language::kLanguagesAvailables::English);

  engine.rootContext()->setContextProperty("depositMoneyView", depositMoneyView.get());
  engine.rootContext()->setContextProperty("withdrawMoneyView", withdrawMoneyView.get());
  engine.rootContext()->setContextProperty("selectFundView", selectFundView.get());
  engine.rootContext()->setContextProperty("transferMoneyView", transferMoneyView.get());

  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
