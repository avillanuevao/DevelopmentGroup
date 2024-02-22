#ifndef FRONTEND_VIEW_DDS_VISUALIZATION_FRONTDDSVIEW_HPP
#define FRONTEND_VIEW_DDS_VISUALIZATION_FRONTDDSVIEW_HPP

#include <memory>
#include <vector>

#include <frontend/source/view/dds/visualization/MessageDDStoAbstractAdapter.hpp>
#include <frontend/source/viewModel/dds/visualization/DDSViewModel.hpp>
#include <idl/bank.hpp>
#include <utils/source/dds/DDSView.hpp>

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
    FrontDDSView(unsigned int domainId,unsigned int sampleCount,
                 std::shared_ptr<frontend::viewModel::dds::visualization::DDSViewModel> ddsViewModel);

  private:
    std::thread initReadingTopicThread(void (frontend::view::dds::visualization::FrontDDSView::*function)());
    void readingTopicMessage();
    void receivedTopicMessage(Message messageSample);

    std::shared_ptr<frontend::viewModel::dds::visualization::DDSViewModel> mDDSViewModel;
    utils::dds::DDSDataReader<Message> mReaderMessage;

};

}  // namespace visualization
}  // namespace view
}  // namespace dds
}  // namespace frontend

#endif  // FRONTEND_VIEW_DDS_VISUALIZATION_FRONTDDSVIEW_HPP
