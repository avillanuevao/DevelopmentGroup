#ifndef FRONTEND_VIEW_DDS_VISUALIZATION_FRONTDDSVIEW_HPP
#define FRONTEND_VIEW_DDS_VISUALIZATION_FRONTDDSVIEW_HPP

#include <memory>
#include <vector>

#include <idl/bank.hpp>

#include <model/source/visualization/message/MessageType.hpp>
#include <model/source/visualization/language/Literals.hpp>
#include <utils/source/dds/DDSView.hpp>
#include <frontend/source/viewModel/dds/visualization/DDSViewModel.hpp>
#include <frontend/source/view/dds/visualization/MessageAdapter.hpp>

namespace frontend
{
namespace view
{
namespace dds
{
namespace visualization
{

class FrontDDSView :
        public utils::dds::DDSView
{
    public:
        FrontDDSView(unsigned int domainId,
                     unsigned int sampleCount,
                     std::shared_ptr<frontend::viewModel::dds::visualization::DDSViewModel> ddsViewModel);

    private:
        void receivedTopicMessage(Message messageSample);
        void readingTopicMessage();
        std::thread initReadingTopicThread(void (frontend::view::dds::visualization::FrontDDSView::*function)());

        std::shared_ptr<frontend::viewModel::dds::visualization::DDSViewModel> m_ddsViewModel;
        utils::dds::DDSDataReader<Message> m_readerMessage;

};

}
}
}
}


#endif // FRONTEND_VIEW_DDS_VISUALIZATION_FRONTDDSVIEW_HPP
