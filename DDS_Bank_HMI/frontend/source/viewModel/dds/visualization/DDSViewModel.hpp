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

        void addMessage(std::time_t date,
                        model::visualization::message::MessageType messageType,
                        std::vector<model::visualization::language::Literals> literals,
                        std::vector<std::string> data);

    private:
        std::shared_ptr<model::visualization::message::AllMessagesInterface> m_allMessageInterface;
};

}
}
}
}


#endif // FRONTEND_VIEWMODEL_DDS_VISUALIZATION_DDSVIEWMODEL_HPP
