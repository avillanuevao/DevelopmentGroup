#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>

#include <model/source/operations/AllFunds.hpp>
#include <model/source/visualization/language/AllLanguages.hpp>
#include <model/source/visualization/message/AllMessages.hpp>
#include <view/ui/operations/SelectFundView.hpp>
#include <view/ui/operations/DepositMoneyView.hpp>
#include <view/ui/operations/WithdrawMoneyView.hpp>
#include <view/ui/operations/TransferMoneyView.hpp>
#include <view/ui/visualization/VisualizeFundView.hpp>
#include <view/ui/visualization/ShowMessageView.hpp>
#include <view/dds/operations/FrontDDSView.hpp>
#include <view/dds/visualization/FrontDDSView.hpp>
#include <view/includeView/visualization/VisualizeFundIncludeView.hpp>
#include <viewModel/ui/operations/Deposit.hpp>
#include <viewModel/ui/operations/Withdraw.hpp>
#include <viewModel/ui/operations/SelectFund.hpp>
#include <viewModel/ui/operations/Transfer.hpp>
#include <viewModel/ui/visualization/VisualizeFundViewModel.hpp>
#include <viewModel/ui/visualization/ShowMessageViewModel.hpp>
#include <viewModel/dds/operations/DDSViewModel.hpp>
#include <viewModel/dds/visualization/DDSViewModel.hpp>

using FrontDDSViewOperations = frontend::view::dds::operations::FrontDDSView;
using FrontDDSViewVisualization = frontend::view::dds::visualization::FrontDDSView;
using DepositMoneyView = frontend::view::ui::operations::DepositMoneyView;
using VisualizeFundView = frontend::view::ui::visualization::VisualizeFundView;
using ShowMessageView = frontend::view::ui::visualization::ShowMessageView;
using SelectFundView = frontend::view::ui::operations::SelectFundView;
using TransferMoneyView = frontend::view::ui::operations::TransferMoneyView;
using VisualizeFundIncludeView = frontend::view::includeView::visualization::VisualizeFundIncludeView;
using WithdrawMoneyView = frontend::view::ui::operations::WithdrawMoneyView;
using DepositViewModel = frontend::viewModel::ui::operations::Deposit;
using DDSViewModelOperations = frontend::viewModel::dds::operations::DDSViewModel;
using DDSViewModelVisualization = frontend::viewModel::dds::visualization::DDSViewModel;
using SelectFundViewModel = frontend::viewModel::ui::operations::SelectFund;
using VisualizeFundViewModel = frontend::viewModel::ui::visualization::VisualizeFundViewModel;
using ShowMessageViewModel = frontend::viewModel::ui::visualization::ShowMessageViewModel;
using WithdrawViewModel = frontend::viewModel::ui::operations::Withdraw;
using TransferViewModel = frontend::viewModel::ui::operations::Transfer;

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    std::shared_ptr<model::operations::AllFunds> allFunds (new model::operations::AllFunds(model::operations::kFundType::Savings));
    std::shared_ptr<model::visualization::message::AllMessages> allMessage(new model::visualization::message::AllMessages());
    std::shared_ptr<model::visualization::language::AllLanguages> allLanguages(
                new model::visualization::language::AllLanguages(model::visualization::language::kLanguagesAvailables::English));

    std::shared_ptr<DepositViewModel> depositViewModel (new DepositViewModel());
    std::shared_ptr<WithdrawViewModel> withdrawViewModel (new WithdrawViewModel());
    std::shared_ptr<DDSViewModelOperations> ddsViewModelOperations (new DDSViewModelOperations(allFunds, allFunds));
    std::shared_ptr<DDSViewModelVisualization> ddsViewModelVisualization (new DDSViewModelVisualization(allMessage));
    std::shared_ptr<VisualizeFundViewModel> visualizeFundViewModel (new VisualizeFundViewModel(allFunds));
    std::shared_ptr<SelectFundViewModel> selectFundViewModel(new SelectFundViewModel());
    std::shared_ptr<TransferViewModel> transferViewModel(new TransferViewModel());
    std::shared_ptr<ShowMessageViewModel> showMessageViewModel(new ShowMessageViewModel());

    std::shared_ptr<DepositMoneyView> depositMoneyView (new DepositMoneyView(depositViewModel, engine));
    std::shared_ptr<WithdrawMoneyView> withdrawMoneyView (new WithdrawMoneyView(withdrawViewModel, engine));
    std::shared_ptr<FrontDDSViewOperations> frontDDSViewOperations (new FrontDDSViewOperations(0, 2, ddsViewModelOperations));
    std::shared_ptr<FrontDDSViewVisualization> frontDDSViewVisualization (new FrontDDSViewVisualization(0, 2, ddsViewModelVisualization));
    std::shared_ptr<VisualizeFundIncludeView> visualizeFundIncludeView (new VisualizeFundIncludeView(visualizeFundViewModel));
    std::shared_ptr<VisualizeFundView> visualizeFundView (new VisualizeFundView(engine));
    std::shared_ptr<SelectFundView> selectFundView(new SelectFundView(selectFundViewModel, engine));
    std::shared_ptr<TransferMoneyView> transferMoneyView(new TransferMoneyView(transferViewModel, engine));
    std::shared_ptr<ShowMessageView> showMessageView(new ShowMessageView(allLanguages, engine));

    allFunds->utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFundType>::addSubscriber(visualizeFundIncludeView);
    allFunds->utils::designPattern::SignalPublisher<model::operations::signal::UpdatedFund>::addSubscriber(visualizeFundIncludeView);

    allMessage->addSubscriber(showMessageViewModel);

    depositViewModel->addSubscriber(frontDDSViewOperations);
    withdrawViewModel->addSubscriber(frontDDSViewOperations);
    visualizeFundViewModel->addSubscriber(visualizeFundView);
    selectFundViewModel->addSubscriber(frontDDSViewOperations);
    transferViewModel->addSubscriber(frontDDSViewOperations);
    showMessageViewModel->addSubscriber(showMessageView);

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
