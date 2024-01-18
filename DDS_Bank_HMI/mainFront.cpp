#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>

#include <model/AllFunds.hpp>
#include <frontend/view/ui/operations/DepositMoneyView.hpp>
#include <frontend/view/dds/operations/FrontDDSView.hpp>
#include <frontend/viewModel/ui/operations/DepositViewModel.hpp>

using DepositViewModel = frontend::viewModel::ui::operations::DepositViewModel;
using DepositMoneyView = frontend::view::ui::operations::DepositMoneyView;
using FrontDDSView = frontend::view::dds::operations::FrontDDSView;

std::shared_ptr<DepositMoneyView> initiate(QQmlApplicationEngine& engine)
{
    std::shared_ptr<model::AllFunds> allFunds =
            std::make_shared<model::AllFunds>();
    std::shared_ptr<DepositViewModel> depositViewModel =
            std::make_shared<DepositViewModel>(allFunds);
    std::shared_ptr<DepositMoneyView> depositViewMoney =
            std::make_shared<DepositMoneyView>(depositViewModel, allFunds, engine);
    std::shared_ptr<FrontDDSView> frontDDSView =
            std::make_shared<FrontDDSView>(allFunds, 0,2);

    depositViewModel->addSubscriber(frontDDSView);
    allFunds->addSubscriber(depositViewMoney);

    return depositViewMoney;
}

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    auto depositViewMoney = initiate(engine);

    engine.rootContext()->setContextProperty("depositViewMoney", &*depositViewMoney);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
