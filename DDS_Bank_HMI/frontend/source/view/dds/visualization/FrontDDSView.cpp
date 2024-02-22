#include "FrontDDSView.hpp"

namespace frontend
{
namespace view
{
namespace dds
{
namespace visualization
{

FrontDDSView::FrontDDSView(unsigned int domainId, unsigned int sampleCount,
                           std::shared_ptr<viewModel::dds::visualization::DDSViewModel> ddsViewModel) :
  utils::dds::DDSView(domainId, sampleCount), mDDSViewModel(ddsViewModel),
  mReaderMessage(
    createDataReader<Message>(
      MESSAGE_TOPIC, std::bind(&FrontDDSView::receivedTopicMessage, this, std::placeholders::_1)))
{
  mThreadsForReading[MESSAGE_TOPIC] = initReadingTopicThread(&FrontDDSView::readingTopicMessage);
}

std::thread FrontDDSView::initReadingTopicThread(
    void (frontend::view::dds::visualization::FrontDDSView::*function)())
{
  return std::thread(function, this);
}

void FrontDDSView::readingTopicMessage()
{
  while(!utils::so::shutdownRequested)
  {
    mReaderMessage.wait(mWait);
  }
}

void FrontDDSView::receivedTopicMessage(Message messageSample)
{
  std::cout << "Message topic recieved: " << "\t" << messageSample << std::endl;

  frontend::view::dds::visualization::MessageDDStoAbstractAdapter message(messageSample);

  mDDSViewModel->addMessage(message);
}

}  // namespace visualization
}  // namespace view
}  // namespace dds
}  // namespace frontend
