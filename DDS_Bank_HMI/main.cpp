#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>

#include <view/DepositMoneyView.hpp>
#include <viewModel/DepositViewModel.hpp>
#include <model/AllFunds.hpp>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    model::AllFunds allFunds;
    viewModel::DepositViewModel depositViewModel(allFunds);
    view::DepositMoneyView depositViewMoney(depositViewModel, allFunds, engine);

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
