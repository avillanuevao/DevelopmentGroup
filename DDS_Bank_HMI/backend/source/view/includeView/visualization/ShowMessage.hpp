#ifndef BACKEND_VIEW_INCLUDEVIEW_VISUALIZATION_SHOWMESSAGE_HPP
#define BACKEND_VIEW_INCLUDEVIEW_VISUALIZATION_SHOWMESSAGE_HPP

#include <memory>

#include <backend/source/controller/operations/signal/ShowMessage.hpp>
#include <backend/source/controller/visualization/ShowMessage.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>

namespace backend
{
namespace view
{
namespace includeView
{
namespace visualization
{

class ShowMessage :
    public utils::designPattern::SignalSubscriber<backend::controller::operations::signal::ShowMessage>
{
  public:
    ShowMessage(std::shared_ptr<backend::controller::visualization::ShowMessage> showMessageController);

    void recievedSignal(backend::controller::operations::signal::ShowMessage signal) override;

  private:
    std::shared_ptr<backend::controller::visualization::ShowMessage> mShowMessageController;
};

}  // namespace visualization
}  // namespace includeView
}  // namespace view
}  // namespace backend

#endif  // BACKEND_VIEW_INCLUDEVIEW_VISUALIZATION_SHOWMESSAGE_HPP
