#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>

#include <model/AllFunds.hpp>
#include <frontend/view/ui/operations/DepositMoneyView.hpp>
#include <frontend/view/dds/operations/FrontDDSView.hpp>
#include <frontend/viewModel/ui/operations/DepositViewModel.hpp>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    model::AllFunds allFunds;
    frontend::viewModel::ui::operations::DepositViewModel depositViewModel(allFunds);
    frontend::view::ui::operations::DepositMoneyView depositViewMoney(depositViewModel, allFunds, engine);
    frontend::view::dds::operations::FrontDDSView frontDDSView(0,2);

    depositViewModel.addSubscriber(frontDDSView);
    allFunds.addSubscriber(depositViewMoney);

    engine.rootContext()->setContextProperty("depositViewMoney", &depositViewMoney);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
