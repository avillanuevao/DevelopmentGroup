#include "Communication.hpp"

namespace frontend
{
namespace view
{
namespace dds
{
namespace visualization
{

Communication::Communication(unsigned int domainId, unsigned int sampleCount,
                             std::shared_ptr<viewModel::dds::visualization::Communication> ddsViewModel) :
  utils::dds::DDSView(domainId, sampleCount), mViewModel(ddsViewModel),
  mReaderMessage(createDataReader<Message>(MESSAGE_TOPIC,
                                           std::bind(&Communication::receivedTopicMessage, this,
                                                     std::placeholders::_1)))
{
  mThreadsForReading[MESSAGE_TOPIC] = initReadingTopicThread(&Communication::readingTopicMessage);
}

std::thread Communication::initReadingTopicThread(
    void (frontend::view::dds::visualization::Communication::*function)())
{
  return std::thread(function, this);
}

void Communication::readingTopicMessage()
{
  while(!utils::so::shutdownRequested)
  {
    mReaderMessage.wait(mWait);
  }
}

void Communication::receivedTopicMessage(Message messageSample)
{
  std::cout << "Message topic recieved: " << "\t" << messageSample << std::endl;

  frontend::view::dds::visualization::MessageDDStoAbstractAdapter message(messageSample);

  mViewModel->addMessage(message);
}

}  // namespace visualization
}  // namespace view
}  // namespace dds
}  // namespace frontend
