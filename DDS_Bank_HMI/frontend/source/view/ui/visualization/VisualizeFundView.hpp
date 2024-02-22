#ifndef FRONTEND_VIEW_UI_VISUALIZATION_VISUALIZEFUNDVIEW_HPP
#define FRONTEND_VIEW_UI_VISUALIZATION_VISUALIZEFUNDVIEW_HPP

#include <iostream>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlComponent>

#include <frontend/source/viewModel/ui/visualization/signal/VisualizeFund.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>

namespace frontend
{
namespace view
{
namespace  ui
{
namespace visualization
{

class VisualizeFundView :
        public QObject,
        public utils::designPattern::SignalSubscriber<frontend::viewModel::ui::visualization::signal::VisualizeFund>
{
    Q_OBJECT

    public:
        VisualizeFundView(QQmlApplicationEngine &engine,
                          QObject *parent = nullptr);

        void recievedSignal(frontend::viewModel::ui::visualization::signal::VisualizeFund signal);

    private slots:
        void updateAmountQML(const QVariant& newAmount);

    private:
        QQmlApplicationEngine& m_engine;
        QObject* m_parent;
};

}
}
}
}
#endif // FRONTEND_VIEW_UI_VISUALIZATION_VISUALIZEFUNDVIEW_HPP
