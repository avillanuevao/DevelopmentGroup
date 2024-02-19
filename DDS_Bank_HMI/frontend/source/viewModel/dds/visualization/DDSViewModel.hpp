#ifndef FRONTEND_VIEWMODEL_DDS_VISUALIZATION_DDSVIEWMODEL_HPP
#define FRONTEND_VIEWMODEL_DDS_VISUALIZATION_DDSVIEWMODEL_HPP

#include <memory>

#include <model/source/visualization/message/AllMessagesInterface.hpp>

namespace frontend
{
namespace viewModel
{
namespace dds
{
namespace visualization
{

class DDSViewModel
{
    public:
        DDSViewModel(std::shared_ptr<model::visualization::message::AllMessagesInterface> allMessageInterface);

        void addMessage(model::visualization::message::MessageInterface message);

    private:
        std::shared_ptr<model::visualization::message::AllMessagesInterface> m_allMessageInterface;
};

}
}
}
}


#endif // FRONTEND_VIEWMODEL_DDS_VISUALIZATION_DDSVIEWMODEL_HPP
