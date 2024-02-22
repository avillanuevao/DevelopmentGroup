#ifndef FRONTEND_VIEW_DDS_VISUALIZATION_MESSAGEDDSTOINTERFACEADAPTER_HPP
#define FRONTEND_VIEW_DDS_VISUALIZATION_MESSAGEDDSTOINTERFACEADAPTER_HPP

#include <idl/bank.hpp>
#include <model/source/visualization/message/aMessage.hpp>

namespace frontend
{
namespace view
{
namespace dds
{
namespace visualization
{

class MessageDDStoInterfaceAdapter:
        public model::visualization::message::aMessage
{
    public:
        MessageDDStoInterfaceAdapter(Message message);

    private:
        std::vector<model::visualization::language::kLiterals> toLiterals(std::vector<int> iLiterals);
        model::visualization::message::aMessage createMessage(Message message);
};

}
}
}
}

#endif // FRONTEND_VIEW_DDS_VISUALIZATION_MESSAGEDDSTOINTERFACEADAPTER_HPP
