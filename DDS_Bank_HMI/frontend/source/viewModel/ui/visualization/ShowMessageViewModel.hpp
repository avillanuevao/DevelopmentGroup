#ifndef FRONTEND_VIEWMODEL_UI_VISUALIZATION_SHOWMESSAGEVIEWMODEL_HPP
#define FRONTEND_VIEWMODEL_UI_VISUALIZATION_SHOWMESSAGEVIEWMODEL_HPP

#include <utils/source/designPattern/SignalSubscriber.hpp>
#include <utils/source/designPattern/SignalPublisher.hpp>
#include <model/source/visualization/message/signal/ShowMessage.hpp>
#include <viewModel/ui/visualization/signal/ShowMessageSignal.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace visualization
{

class ShowMessageViewModel :
        public utils::designPattern::SignalSubscriber<model::visualization::message::signal::ShowMessage>,
        public utils::designPattern::SignalPublisher<frontend::viewModel::ui::visualization::signal::ShowMessageSignal>
{
    public:
        ShowMessageViewModel();

        void recievedSignal(model::visualization::message::signal::ShowMessage signal);
};

}
}
}
}


#endif // FRONTEND_VIEWMODEL_UI_VISUALIZATION_SHOWMESSAGEVIEWMODEL_HPP
