#ifndef MODEL_VISUALIZATION_ALLMESSAGESINTERFACE_HPP
#define MODEL_VISUALIZATION_ALLMESSAGESINTERFACE_HPP

#include<visualization/MessageInterface.hpp>

namespace model
{
namespace visualization
{

class AllMessagesInterface
{
    public:
        AllMessagesInterface();

        virtual void addMessage(model::visualization::MessageInterface newMessage) = 0;
};

}
}

#endif // MODEL_VISUALIZATION_ALLMESSAGESINTERFACE_HPP
