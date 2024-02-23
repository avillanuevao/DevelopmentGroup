#ifndef FRONTEND_VIEWMODEL_UI_VISUALIZATION_SIGNAL_SHOWMESSAGE_HPP
#define FRONTEND_VIEWMODEL_UI_VISUALIZATION_SIGNAL_SHOWMESSAGE_HPP

#include <model/source/visualization/message/aMessage.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace visualization
{
namespace signal
{

class ShowMessage
{
  public:
    ShowMessage(model::visualization::message::aMessage message);

    const model::visualization::message::aMessage getMessage() const;

  private:
    model::visualization::message::aMessage mMessage;
};

}  // namespace signal
}  // namespace visualization
}  // namespace ui
}  // namespace viewModel
}  // namespace frontend

#endif  // FRONTEND_VIEWMODEL_UI_VISUALIZATION_SIGNAL_SHOWMESSAGE_HPP
