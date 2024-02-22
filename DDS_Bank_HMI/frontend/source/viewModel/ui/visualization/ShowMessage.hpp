#ifndef FRONTEND_VIEWMODEL_UI_VISUALIZATION_SHOWMESSAGEL_HPP
#define FRONTEND_VIEWMODEL_UI_VISUALIZATION_SHOWMESSAGEL_HPP

#include <model/source/visualization/message/signal/ShowMessage.hpp>
#include <utils/source/designPattern/SignalPublisher.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>
#include <viewModel/ui/visualization/signal/ShowMessage.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace visualization
{

class ShowMessage :
    public utils::designPattern::SignalSubscriber<model::visualization::message::signal::ShowMessage>,
    public utils::designPattern::SignalPublisher<frontend::viewModel::ui::visualization::signal::ShowMessage>
{
  public:
    ShowMessage();

    void recievedSignal(model::visualization::message::signal::ShowMessage signal);
};

}  // namespace visualization
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend

#endif  // FRONTEND_VIEWMODEL_UI_VISUALIZATION_SHOWMESSAGE_HPP
