#ifndef FRONTEND_VIEW_UI_VISUALIZATION_VISUALIZE_HPP
#define FRONTEND_VIEW_UI_VISUALIZATION_VISUALIZE_HPP

#include <iostream>
#include <memory>

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickWindow>

#include <frontend/source/viewModel/ui/visualization/signal/UpdatedLanguage.hpp>
#include <model/source/visualization/language/aLanguage.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>

namespace frontend
{
namespace view
{
namespace  ui
{
namespace visualization
{

class Visualize :
    public QObject,
    public utils::designPattern::SignalSubscriber<
    frontend::viewModel::ui::visualization::signal::UpdatedLanguage>
{
    Q_OBJECT
  public:
    Visualize(QQmlApplicationEngine& engine, QObject* parent = nullptr);

    void recievedSignal(frontend::viewModel::ui::visualization::signal::UpdatedLanguage signal) override;

  private slots:
    void showMessageQML(QString objectName, QString property, QString propertyValue);

  private:
    const std::shared_ptr<model::visualization::language::aLanguage> mLanguage;
    QQmlApplicationEngine& mEngine;
    QObject* mParent;
};

}  // namespace visualization
}  // namespace ui
}  // namespace view
}  // namespace frontend

#endif  // FRONTEND_VIEW_UI_VISUALIZATION_VISUALIZE_HPP
