#ifndef FRONTEND_VIEW_UI_VISUALIZATION_SHOWMESSAGE_HPP
#define FRONTEND_VIEW_UI_VISUALIZATION_SHOWMESSAGE_HPP

#include <iostream>

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickWindow>

#include <frontend/source/viewModel/ui/visualization/signal/ShowMessage.hpp>
#include <model/source/visualization/language/aLanguage.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>

namespace frontend
{
namespace view
{
namespace ui
{
namespace visualization
{

class ShowMessage:
    public QObject,
    public utils::designPattern::SignalSubscriber<frontend::viewModel::ui::visualization::signal::ShowMessage>
{
    Q_OBJECT

  public:
    ShowMessage(std::shared_ptr<model::visualization::language::aLanguage> language,
                    QQmlApplicationEngine& engine, QObject* parent = nullptr);

    void recievedSignal(frontend::viewModel::ui::visualization::signal::ShowMessage signal) override;

    const QColor kMessageSuccess = "#008F39";
    const QColor kMessageFailure = "#CB3234";
    const QColor kMessageWarning = "#FF8000";

  private slots:
    void showMessageQML(const QVariant& message, const QVariant& color);

  private:
    QColor colorMessage(model::visualization::message::kMessageType messageType);
    std::string composeMessage(model::visualization::message::aMessage messageInterface);
    std::string formatMessageType(model::visualization::message::kMessageType messageType);
    std::string formatDate(std::time_t date);

    std::shared_ptr<model::visualization::language::aLanguage> mLanguage;
    QQmlApplicationEngine& mEngine;
    QObject* mParent;
};

}  // namespace visualization
}  // namespace ui
}  // namespace view
}  // namespace frontend

#endif  // FRONTEND_VIEW_UI_VISUALIZATION_SHOWMESSAGE_HPP
