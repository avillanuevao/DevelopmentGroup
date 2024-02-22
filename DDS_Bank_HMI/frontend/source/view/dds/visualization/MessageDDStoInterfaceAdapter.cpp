#include "MessageDDStoInterfaceAdapter.hpp"

namespace frontend
{
namespace view
{
namespace dds
{
namespace visualization
{

MessageDDStoInterfaceAdapter::MessageDDStoInterfaceAdapter(Message message):
    model::visualization::message::aMessage(createMessage(message))
{

}

std::vector<model::visualization::language::kLiterals> MessageDDStoInterfaceAdapter::toLiterals(std::vector<int> iLiterals)
{
    std::vector<model::visualization::language::kLiterals> literals;

    for(int elem: iLiterals)
    {
        literals.push_back(model::visualization::language::kLiterals::_from_integral(elem));
    }

    return literals;
}

model::visualization::message::aMessage MessageDDStoInterfaceAdapter::createMessage(Message message)
{
    int ddsMessageType = static_cast<int>(message.message_type());
    std::vector<int> iLiterals (message.literals().begin(), message.literals().end());

    std::time_t date = message.date();
    model::visualization::message::kMessageType modelMessageType = model::visualization::message::kMessageType::_from_index(ddsMessageType);
    std::vector<model::visualization::language::kLiterals> literals = toLiterals(iLiterals);
    std::vector<std::string> data(message.data().begin(), message.data().end());

    return model::visualization::message::aMessage(date, modelMessageType, literals, data);
}

}
}
}
}
