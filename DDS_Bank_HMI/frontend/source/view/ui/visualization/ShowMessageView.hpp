#ifndef FRONTEND_VIEW_UI_VISUALIZATION_SHOWMESSAGEVIEW_HPP
#define FRONTEND_VIEW_UI_VISUALIZATION_SHOWMESSAGEVIEW_HPP

#include <iostream>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlComponent>

#include <model/source/visualization/language/AllLanguagesInterface.hpp>
#include <frontend/source/viewModel/ui/visualization/signal/ShowMessageSignal.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>

namespace frontend
{
namespace view
{
namespace ui
{
namespace visualization
{

class ShowMessageView:
        public QObject,
        public utils::designPattern::SignalSubscriber<frontend::viewModel::ui::visualization::signal::ShowMessageSignal>
{
    Q_OBJECT

    public:
        ShowMessageView(std::shared_ptr<model::visualization::language::AllLanguagesInterface> allLanguages,
                QQmlApplicationEngine &engine,
                QObject *parent = nullptr);

         void recievedSignal(frontend::viewModel::ui::visualization::signal::ShowMessageSignal signal) override;

    private slots:
        void showMessageQML(const QVariant& message, const QVariant& color);

    private:
        QColor colorMessage(model::visualization::message::MessageType messageType);
        std::string composeMessage(model::visualization::message::MessageInterface messageInterface);

        const QColor MESSAGE_SUCCESS = "#00FF00";
        const QColor MESSAGE_FAILURE = "#FF0000";
        const QColor MESSAGE_WARNING = "#FFA500";
        std::shared_ptr<model::visualization::language::AllLanguagesInterface> m_allLanguages;
        QQmlApplicationEngine& m_engine;
        QObject* m_parent;
};

}
}
}
}


#endif // FRONTEND_VIEW_UI_VISUALIZATION_SHOWMESSAGEVIEW_HPP
