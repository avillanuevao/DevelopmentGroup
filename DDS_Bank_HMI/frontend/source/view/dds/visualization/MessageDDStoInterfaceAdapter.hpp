#ifndef FRONTEND_VIEW_DDS_VISUALIZATION_MESSAGEDDSTOINTERFACEADAPTER_HPP
#define FRONTEND_VIEW_DDS_VISUALIZATION_MESSAGEDDSTOINTERFACEADAPTER_HPP

#include <idl/bank.hpp>
#include <model/source/visualization/message/MessageInterface.hpp>

namespace frontend
{
namespace view
{
namespace dds
{
namespace visualization
{

class MessageDDStoInterfaceAdapter:
        public model::visualization::message::MessageInterface
{
    public:
        MessageDDStoInterfaceAdapter(Message message);

    private:
        std::vector<model::visualization::language::Literals> toLiterals(std::vector<int> iLiterals);
        model::visualization::message::MessageInterface createMessage(Message message);
};

}
}
}
}

#endif // FRONTEND_VIEW_DDS_VISUALIZATION_MESSAGEDDSTOINTERFACEADAPTER_HPP
