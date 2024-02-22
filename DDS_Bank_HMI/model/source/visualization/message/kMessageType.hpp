#ifndef MODEL_VISUALIZATION_MESSAGE_KMESSAGETYPE_HPP
#define MODEL_VISUALIZATION_MESSAGE_KMESSAGETYPE_HPP

#include <enum.hpp>

namespace model
{
namespace visualization
{
namespace message
{

BETTER_ENUM(kMessageType, int,
            Success,
            Failure,
            Warning)

}  // namespace message
}  // namespace visualization
}  // namespace model

#endif  // MODEL_VISUALIZATION_MESSAGE_KMESSAGETYPE_HPP
