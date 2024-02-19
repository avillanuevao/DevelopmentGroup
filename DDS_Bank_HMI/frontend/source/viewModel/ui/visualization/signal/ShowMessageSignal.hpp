#ifndef FRONTEND_VIEWMODEL_UI_VISUALIZATION_SIGANL_SHOWMESSAGESIGNAL_HPP
#define FRONTEND_VIEWMODEL_UI_VISUALIZATION_SIGANL_SHOWMESSAGESIGNAL_HPP

#include <model/source/visualization/message/MessageInterface.hpp>

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
        ShowMessageSignal(model::visualization::message::MessageInterface message);

    private:
        model::visualization::message::MessageInterface m_message;
};

}
}
}
}
}


#endif // FRONTEND_VIEWMODEL_UI_VISUALIZATION_SIGANL_SHOWMESSAGESIGNAL_HPP
