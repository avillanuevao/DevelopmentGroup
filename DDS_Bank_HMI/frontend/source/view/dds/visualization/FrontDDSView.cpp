#include "FrontDDSView.hpp"

namespace frontend
{
namespace view
{
namespace dds
{
namespace visualization
{

FrontDDSView::FrontDDSView(unsigned int domainId,
                           unsigned int sampleCount,
                           std::shared_ptr<viewModel::dds::visualization::DDSViewModel> ddsViewModel) :
    utils::dds::DDSView(domainId, sampleCount),
    m_ddsViewModel(ddsViewModel),
    m_readerMessage(createDataReader<Message>(MESSAGE_TOPIC, std::bind(&FrontDDSView::receivedTopicMessage, this, std::placeholders::_1)))
{
    m_threadsForReading[MESSAGE_TOPIC] = initReadingTopicThread(&FrontDDSView::readingTopicMessage);
}

void FrontDDSView::receivedTopicMessage(Message messageSample)
{
    std::cout << "Message topic recieved: " << std::endl;
    std::cout << "\t" << messageSample << std::endl;

    frontend::view::dds::visualization::MessageDDStoInterfaceAdapter message(messageSample);

    m_ddsViewModel->addMessage(message);
}

void FrontDDSView::readingTopicMessage()
{
    while(!utils::so::shutdown_requested)
    {
        m_readerMessage.wait(m_wait);
    }
}

std::thread FrontDDSView::initReadingTopicThread(void (frontend::view::dds::visualization::FrontDDSView::*function)())
{
    return std::thread(function, this);
}

}
}
}
}
