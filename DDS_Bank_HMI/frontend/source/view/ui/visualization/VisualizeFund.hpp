#ifndef FRONTEND_VIEW_UI_VISUALIZATION_VISUALIZEFUND_HPP
#define FRONTEND_VIEW_UI_VISUALIZATION_VISUALIZEFUND_HPP

#include <iostream>

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickWindow>

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

class VisualizeFund :
    public QObject,
    public utils::designPattern::SignalSubscriber<
      frontend::viewModel::ui::visualization::signal::VisualizeFund>
{
    Q_OBJECT

  public:
    VisualizeFund(QQmlApplicationEngine& engine, QObject* parent = nullptr);

    void recievedSignal(frontend::viewModel::ui::visualization::signal::VisualizeFund signal);

  private slots:
    void updateAmountQML(const QVariant& newAmount);

  private:
    QQmlApplicationEngine& mEngine;
    QObject* mParent;
};

}  // namespace visualization
}  // namespace ui
}  // namespace view
}  // namespace frontend

#endif  // FRONTEND_VIEW_UI_VISUALIZATION_VISUALIZEFUND_HPP
