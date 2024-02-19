#ifndef MODEL_VISUALIZATION_MESSAGE_SIGNAL_SHOWMESSAGESIGNAL_HPP
#define MODEL_VISUALIZATION_MESSAGE_SIGNAL_SHOWMESSAGESIGNAL_HPP

#include <visualization/message/MessageInterface.hpp>

namespace model
{
namespace visualization
{
namespace message
{
namespace signal
{

class ShowMessageSignal
{
    public:
        ShowMessageSignal(model::visualization::message::MessageInterface message);

        const model::visualization::message::MessageInterface getMessage() const;

private:
        model::visualization::message::MessageInterface m_message;
};

}
}
}
}

#endif // MODEL_VISUALIZATION_MESSAGE_SIGNAL_SHOWMESSAGESIGNAL_HPP
