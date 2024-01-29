#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>

#include <model/source/AllFunds.hpp>
#include <frontend/source/view/dds/operations/FrontDDSView.hpp>
#include <frontend/source/view/ui/operations/DepositMoneyView.hpp>
#include <frontend/source/view/ui/operations/WithdrawMoneyView.hpp>
#include <frontend/source/view/ui/operations/TransferMoneyView.hpp>
#include <frontend/source/viewModel/signal/DepositMoneySignal.hpp>
#include <frontend/source/viewModel/signal/WithdrawnMoneySignal.hpp>
#include <frontend/source/viewModel/signal/TransferedMoneySignal.hpp>
#include <frontend/source/viewModel/ui/operations/DepositViewModel.hpp>
#include <frontend/source/viewModel/ui/operations/WithdrawViewModel.hpp>
#include <frontend/source/viewModel/ui/operations/TransferViewModel.hpp>

using FrontDDSView = frontend::view::dds::operations::FrontDDSView;
using DepositMoneyView = frontend::view::ui::operations::DepositMoneyView;
using WithdrawMoneyView = frontend::view::ui::operations::WithdrawMoneyView;

using DepositViewModel = frontend::viewModel::ui::operations::DepositViewModel;
using WithdrawViewModel = frontend::viewModel::ui::operations::WithdrawViewModel;



using TransferMoneyView = frontend::view::ui::operations::TransferMoneyView;
using TransferViewModel = frontend::viewModel::ui::operations::TransferViewModel;

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    std::shared_ptr<model::AllFunds> allFunds =
            std::make_shared<model::AllFunds>();

    std::shared_ptr<DepositViewModel> depositViewModel =
            std::make_shared<DepositViewModel>(allFunds);
    std::shared_ptr<DepositMoneyView> depositMoneyView =
            std::make_shared<DepositMoneyView>(depositViewModel, allFunds, engine);

    std::shared_ptr<WithdrawViewModel> withdrawViewModel =
            std::make_shared<WithdrawViewModel>(allFunds);
    std::shared_ptr<WithdrawMoneyView> withdrawMoneyView =
            std::make_shared<WithdrawMoneyView>(withdrawViewModel, allFunds, engine);

    std::shared_ptr<FrontDDSView> frontDDSView =
            std::make_shared<FrontDDSView>(allFunds, 0,2);

    allFunds->utils::designPattern::SignalPublisher<model::signal::MoneyDepositedSignal>::addSubscriber(depositViewModel);
    allFunds->utils::designPattern::SignalPublisher<model::signal::MoneyWithdrawnSignal>::addSubscriber(withdrawViewModel);

    depositViewModel->utils::designPattern::SignalPublisher<frontend::viewModel::signal::MoneyDepositedSignal>::addSubscriber(depositMoneyView);
    depositViewModel->utils::designPattern::SignalPublisher<frontend::viewModel::signal::DepositMoneySignal>::addSubscriber(frontDDSView);

    withdrawViewModel->utils::designPattern::SignalPublisher<frontend::viewModel::signal::MoneyWithdrawnSignal>::addSubscriber(withdrawMoneyView);
    withdrawViewModel->utils::designPattern::SignalPublisher<frontend::viewModel::signal::WithdrawnMoneySignal>::addSubscriber(frontDDSView);

    std::shared_ptr<TransferViewModel> transferViewModel =
            std::make_shared<TransferViewModel>(allFunds);
    std::shared_ptr<TransferMoneyView> transferMoneyView =
            std::make_shared<TransferMoneyView>(transferViewModel, allFunds,engine);
    allFunds->utils::designPattern::SignalPublisher<model::signal::MoneyTransferedSignal>::addSubscriber(transferViewModel);
    transferViewModel->utils::designPattern::SignalPublisher<frontend::viewModel::signal::MoneyTransferedSignal>::addSubscriber(transferMoneyView);
    transferViewModel->utils::designPattern::SignalPublisher<frontend::viewModel::signal::TransferedMoneySignal>::addSubscriber(frontDDSView);
    engine.rootContext()->setContextProperty("depositMoneyView", &*depositMoneyView);
    engine.rootContext()->setContextProperty("withdrawMoneyView", &*withdrawMoneyView);
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
