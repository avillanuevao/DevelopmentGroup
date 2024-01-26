#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>

#include <model/source/AllFunds.hpp>
#include <frontend/source/view/ui/operations/DepositMoneyView.hpp>
#include <frontend/source/view/dds/operations/FrontDDSView.hpp>
#include <frontend/source/viewModel/ui/operations/DepositViewModel.hpp>
#include <frontend/source/viewModel/signal/DepositMoneySignal.hpp>

#include <frontend/source/view/ui/operations/TransferMoneyView.hpp>
#include <frontend/source/viewModel/ui/operations/TransferViewModel.hpp>
#include <frontend/source/viewModel/signal/TransferedMoneySignal.hpp>

using DepositViewModel = frontend::viewModel::ui::operations::DepositViewModel;
using DepositMoneyView = frontend::view::ui::operations::DepositMoneyView;
using FrontDDSView = frontend::view::dds::operations::FrontDDSView;

using TransferMoneyView = frontend::view::ui::operations::TransferMoneyView;
using TransferViewModel = frontend::viewModel::ui::operations::TransferViewModel;

std::shared_ptr<DepositMoneyView> initiate(QQmlApplicationEngine& engine)
{
    std::shared_ptr<model::AllFunds> allFunds =
            std::make_shared<model::AllFunds>();
    std::shared_ptr<DepositViewModel> depositViewModel =
            std::make_shared<DepositViewModel>(allFunds);
    std::shared_ptr<DepositMoneyView> depositMoneyView =
            std::make_shared<DepositMoneyView>(depositViewModel, allFunds, engine);
    std::shared_ptr<FrontDDSView> frontDDSView =
            std::make_shared<FrontDDSView>(allFunds, 0,2);

    allFunds->addSubscriber(depositViewModel);
    depositViewModel->utils::designPattern::SignalPublisher<frontend::viewModel::signal::MoneyDepositedSignal>::addSubscriber(depositMoneyView);
    depositViewModel->utils::designPattern::SignalPublisher<frontend::viewModel::signal::DepositMoneySignal>::addSubscriber(frontDDSView);

    return depositMoneyView;
}

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

//    auto depositMoneyView = initiate(engine);

//    engine.rootContext()->setContextProperty("depositMoneyView", &*depositMoneyView);

    std::shared_ptr<model::AllFunds> allFunds = std::make_shared<model::AllFunds>();
    std::shared_ptr<TransferViewModel> transferViewModel = std::make_shared<TransferViewModel>(allFunds);
    std::shared_ptr<TransferMoneyView> transferMoneyView =
            std::make_shared<TransferMoneyView>(transferViewModel, allFunds,engine);
    std::shared_ptr<FrontDDSView> frontDDSView =
            std::make_shared<FrontDDSView>(allFunds, 0,2);
    transferViewModel->utils::designPattern::SignalPublisher<frontend::viewModel::signal::TransferedMoneySignal>::addSubscriber(frontDDSView);

    engine.rootContext()->setContextProperty("transferMoneyView", &*transferMoneyView);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
