#ifndef BACKEND_VIEW_INCLUDEVIEW_VISUALIZATION_SHOWMESSAGEINCLUDEVIEW_HPP
#define BACKEND_VIEW_INCLUDEVIEW_VISUALIZATION_SHOWMESSAGEINCLUDEVIEW_HPP

#include <memory>

#include <utils/source/designPattern/SignalSubscriber.hpp>
#include <backend/source/controller/operations/signal/ShowMessageSignal.hpp>
#include <backend/source/controller/visualization/ShowMessageController.hpp>

namespace backend
{
namespace view
{
namespace includeView
{
namespace visualization
{

class ShowMessageIncludeView :
        public utils::designPattern::SignalSubscriber<backend::controller::operations::signal::ShowMessageSignal>
{
    public:
        ShowMessageIncludeView(std::shared_ptr<backend::controller::visualization::ShowMessageController> showMessageController);

        void recievedSignal(backend::controller::operations::signal::ShowMessageSignal signal) override;

    private:
        std::shared_ptr<backend::controller::visualization::ShowMessageController> m_showMessageController;
};

}
}
}
}



#endif // BACKEND_VIEW_INCLUDEVIEW_VISUALIZATION_SHOWMESSAGEINCLUDEVIEW_HPP
