#ifndef MODEL_VISUALIZATION_MESSAGE_MESSAGETYPE_HPP
#define MODEL_VISUALIZATION_MESSAGE_MESSAGETYPE_HPP

#include <enum.hpp>

namespace model
{
namespace visualization
{
namespace message
{

BETTER_ENUM(MessageType, int,
            SUCCESS,
            FAILURE,
            WARNING)

}
}
}

#endif // MODEL_VISUALIZATION_MESSAGE_MESSAGETYPE_HPP
