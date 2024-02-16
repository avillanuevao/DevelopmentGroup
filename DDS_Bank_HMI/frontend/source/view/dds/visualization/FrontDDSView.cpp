#include "FrontDDSView.hpp"
#include <utils/source/so/Shutdown.hpp>

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

}

void FrontDDSView::receivedTopicMessage(Message messageSample)
{
    std::cout << "Message topic recieved: " << std::endl;
    std::cout << "\t" << messageSample << std::endl;

    addMessage(messageSample);
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

std::vector<model::visualization::language::Literals> FrontDDSView::toLiterals(std::vector<int> iLiterals)
{
    std::vector<model::visualization::language::Literals> literals;

    for(int elem: iLiterals)
    {
        literals.push_back(model::visualization::language::Literals::_from_integral(elem));
    }

    return literals;
}

void FrontDDSView::addMessage(Message messageSample)
{
    std::time_t date = messageSample.date();
    int ddsMessageType = static_cast<int>(messageSample.message_type());
    model::visualization::message::MessageType modelMessageType = model::visualization::message::MessageType::_from_index(ddsMessageType);
    std::vector<int> iLiterals (messageSample.literals().begin(), messageSample.literals().end());
    std::vector<model::visualization::language::Literals> literals = toLiterals(iLiterals);
    std::vector<std::string> data (messageSample.data().begin(), messageSample.data().end());

    m_ddsViewModel->addMessage(date, modelMessageType, literals, data);
}

}
}
}
}
