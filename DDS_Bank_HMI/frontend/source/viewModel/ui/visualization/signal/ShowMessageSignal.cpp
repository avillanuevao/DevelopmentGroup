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

ShowMessageSignal::ShowMessageSignal(model::visualization::message::aMessage message) :
    m_message(message)
{

}

const model::visualization::message::aMessage ShowMessageSignal::getMessage() const
{
    return m_message;
}

}
}
}
}
}
