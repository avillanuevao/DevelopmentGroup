#ifndef FRONTEND_VIEWMODEL_UI_VISUALIZATION_SIGANL_SHOWMESSAGESIGNAL_HPP
#define FRONTEND_VIEWMODEL_UI_VISUALIZATION_SIGANL_SHOWMESSAGESIGNAL_HPP

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

class ShowMessageSignal
{
    public:
        ShowMessageSignal(model::visualization::message::aMessage message);

        const model::visualization::message::aMessage getMessage() const;

    private:
        model::visualization::message::aMessage m_message;
};

}
}
}
}
}


#endif // FRONTEND_VIEWMODEL_UI_VISUALIZATION_SIGANL_SHOWMESSAGESIGNAL_HPP
