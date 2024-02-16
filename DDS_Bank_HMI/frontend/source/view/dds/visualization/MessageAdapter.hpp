#ifndef MESSAGEADAPTER_HPP
#define MESSAGEADAPTER_HPP

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

class MessageAdapter:
        public model::visualization::message::MessageInterface
{
    public:
        MessageAdapter(Message message);

    private:
        std::vector<model::visualization::language::Literals> toLiterals(std::vector<int> iLiterals);
        model::visualization::message::MessageInterface createMessage(Message message);
};

}
}
}
}

#endif // MESSAGEADAPTER_HPP
