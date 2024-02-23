#ifndef MODEL_VISUALIZATION_KOPERATIONTYPE_HPP
#define MODEL_VISUALIZATION_KOPERATIONTYPE_HPP

#include <enum.hpp>

namespace model
{
namespace visualization
{
namespace message
{

BETTER_ENUM(kOperationType, int,
            Deposit,
            Withdraw,
            Transfer)

}  // namespace message
}  // namespace visualization
}  // namespace model

#endif  // MODEL_VISUALIZATION_KOPERATIONTYPE_HPP
