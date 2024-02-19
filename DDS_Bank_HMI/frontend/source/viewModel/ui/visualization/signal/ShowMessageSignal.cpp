#include "ShowMessageSignal.hpp"

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace visualization
{
namespace signal
{

ShowMessageSignal::ShowMessageSignal(model::visualization::message::MessageInterface message) :
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
}
