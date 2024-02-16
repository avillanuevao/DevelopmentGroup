#include "MessageAdapter.hpp"

namespace frontend
{
namespace view
{
namespace dds
{
namespace visualization
{

MessageAdapter::MessageAdapter(Message message):
    model::visualization::message::MessageInterface(createMessage(message))
{

}

std::vector<model::visualization::language::Literals> MessageAdapter::toLiterals(std::vector<int> iLiterals)
{
    std::vector<model::visualization::language::Literals> literals;

    for(int elem: iLiterals)
    {
        literals.push_back(model::visualization::language::Literals::_from_integral(elem));
    }

    return literals;
}

model::visualization::message::MessageInterface MessageAdapter::createMessage(Message message)
{
    int ddsMessageType = static_cast<int>(message.message_type());
    std::vector<int> iLiterals (message.literals().begin(), message.literals().end());

    std::time_t date = message.date();
    model::visualization::message::MessageType modelMessageType = model::visualization::message::MessageType::_from_index(ddsMessageType);
    std::vector<model::visualization::language::Literals> literals = toLiterals(iLiterals);
    std::vector<std::string> data(message.data().begin(), message.data().end());

    return model::visualization::message::MessageInterface(date, modelMessageType, literals, data);
}

}
}
}
}
