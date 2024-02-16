#include "DDSViewModel.hpp"

namespace frontend
{
namespace viewModel
{
namespace dds
{
namespace visualization
{

DDSViewModel::DDSViewModel(std::shared_ptr<model::visualization::message::AllMessagesInterface> allMessageInterface) :
    m_allMessageInterface(allMessageInterface)
{

}

void DDSViewModel::addMessage(time_t date,
                              model::visualization::message::MessageType messageType,
                              std::vector<model::visualization::language::Literals> literals,
                              std::vector<std::string> data)
{
    model::visualization::message::MessageInterface message(date, messageType, literals, data);
    m_allMessageInterface->addMessage(message);
}

}
}
}
}
