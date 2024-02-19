#include "ShowMessageSignal.hpp"

namespace model
{
namespace visualization
{
namespace message
{
namespace signal
{

ShowMessageSignal::ShowMessageSignal(MessageInterface message) :
    m_message(message)
{

}

const model::visualization::message::MessageInterface ShowMessageSignal::getMessage() const
{
    return m_message;
}

}
}
}
}
