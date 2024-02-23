#ifndef FRONTEND_VIEW_DDS_VISUALIZATION_COMMUNICATION_HPP
#define FRONTEND_VIEW_DDS_VISUALIZATION_COMMUNICATION_HPP

#include <memory>
#include <vector>

#include <frontend/source/view/dds/visualization/MessageDDStoAbstractAdapter.hpp>
#include <frontend/source/viewModel/dds/visualization/Communication.hpp>
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

class Communication :
    public utils::dds::DDSView
{
  public:
    Communication(unsigned int domainId,unsigned int sampleCount,
                 std::shared_ptr<frontend::viewModel::dds::visualization::Communication> ddsViewModel);

  private:
    std::thread initReadingTopicThread(void (frontend::view::dds::visualization::Communication::*function)());
    void readingTopicMessage();
    void receivedTopicMessage(Message messageSample);

    std::shared_ptr<frontend::viewModel::dds::visualization::Communication> mViewModel;
    utils::dds::DDSDataReader<Message> mReaderMessage;

};

}  // namespace visualization
}  // namespace view
}  // namespace dds
}  // namespace frontend

#endif  // FRONTEND_VIEW_DDS_VISUALIZATION_COMMUNICATION_HPP
