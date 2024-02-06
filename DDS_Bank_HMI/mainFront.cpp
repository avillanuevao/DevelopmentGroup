#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>

#include <model/source/AllFunds.hpp>
#include <view/ui/operations/DepositMoneyView.hpp>
#include <view/ui/operations/WithdrawMoneyView.hpp>
#include <view/ui/operations/TransferMoneyView.hpp>
#include <view/ui/visualization/VisualizeFundView.hpp>
#include <view/dds/operations/FrontDDSView.hpp>
#include <view/includeView/visualization/VisualizeFundIncludeView.hpp>
#include <viewModel/ui/operations/DepositViewModel.hpp>
#include <viewModel/ui/operations/WithdrawViewModel.hpp>
#include <viewModel/ui/operations/SelectFundViewModel.hpp>
#include <viewModel/ui/operations/TransferViewModel.hpp>
#include <viewModel/ui/visualization/VisualizeFundViewModel.hpp>
#include <viewModel/dds/operations/DDSViewModel.hpp>

using FrontDDSView = frontend::view::dds::operations::FrontDDSView;
using DepositMoneyView = frontend::view::ui::operations::DepositMoneyView;
using VisualizeFundView = frontend::view::ui::visualization::VisualizeFundView;
using SelectFundView = frontend::view::ui::operations::SelectFundView;
using TransferMoneyView = frontend::view::ui::operations::TransferMoneyView;
using VisualizeFundIncludeView = frontend::view::includeView::visualization::VisualizeFundIncludeView;
using WithdrawMoneyView = frontend::view::ui::operations::WithdrawMoneyView;
using DepositViewModel = frontend::viewModel::ui::operations::DepositViewModel;
using DDSViewModel = frontend::viewModel::dds::operations::DDSViewModel;
using SelectFundViewModel = frontend::viewModel::ui::operations::SelectFundViewModel;
using VisualizeFundViewModel = frontend::viewModel::ui::visualization::VisualizeFundViewModel;
using WithdrawViewModel = frontend::viewModel::ui::operations::WithdrawViewModel;
using TransferViewModel = frontend::viewModel::ui::operations::TransferViewModel;

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    std::shared_ptr<model::AllFunds> allFunds (new model::AllFunds(model::FundType::SAVINGS));

    std::shared_ptr<DepositViewModel> depositViewModel (new DepositViewModel());
    std::shared_ptr<WithdrawViewModel> withdrawViewModel (new WithdrawViewModel());
    std::shared_ptr<DDSViewModel> ddsViewModel (new DDSViewModel(allFunds, allFunds));
    std::shared_ptr<VisualizeFundViewModel> visualizeFundViewModel (new VisualizeFundViewModel(allFunds));
    std::shared_ptr<SelectFundViewModel> selectFundViewModel(new SelectFundViewModel());
    std::shared_ptr<TransferViewModel> transferViewModel(new TransferViewModel());

    std::shared_ptr<DepositMoneyView> depositMoneyView (new DepositMoneyView(depositViewModel, engine));
    std::shared_ptr<WithdrawMoneyView> withdrawMoneyView (new WithdrawMoneyView(withdrawViewModel, engine));
    std::shared_ptr<FrontDDSView> frontDDSView (new FrontDDSView(0, 2, ddsViewModel));
    std::shared_ptr<VisualizeFundIncludeView> visualizeFundIncludeView (new VisualizeFundIncludeView(visualizeFundViewModel));
    std::shared_ptr<VisualizeFundView> visualizeFundView (new VisualizeFundView(engine));
    std::shared_ptr<SelectFundView> selectFundView(new SelectFundView(selectFundViewModel, engine));
    std::shared_ptr<TransferMoneyView> transferMoneyView(new TransferMoneyView(transferViewModel, engine));

    allFunds->utils::designPattern::SignalPublisher<model::signal::UpdatedFundTypeSignal>::addSubscriber(visualizeFundIncludeView);
    allFunds->utils::designPattern::SignalPublisher<model::signal::UpdatedFundSignal>::addSubscriber(visualizeFundIncludeView);

    depositViewModel->addSubscriber(frontDDSView);
    withdrawViewModel->addSubscriber(frontDDSView);
    visualizeFundViewModel->addSubscriber(visualizeFundView);
    selectFundViewModel->addSubscriber(frontDDSView);
    transferViewModel->addSubscriber(frontDDSView);

    engine.rootContext()->setContextProperty("depositMoneyView", &*depositMoneyView);
    engine.rootContext()->setContextProperty("withdrawMoneyView", &*withdrawMoneyView);
    engine.rootContext()->setContextProperty("selectFundView", &*selectFundView);
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
