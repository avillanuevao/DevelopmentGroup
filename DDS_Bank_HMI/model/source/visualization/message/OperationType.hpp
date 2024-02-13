#ifndef MODEL_VISUALIZATION_OPERATIONTYPE_HPP
#define MODEL_VISUALIZATION_OPERATIONTYPE_HPP

#include <enum.hpp>

namespace model
{
namespace visualization
{
namespace message
{

BETTER_ENUM(OperationType, int,
            DEPOSIT,
            WITHDRAW,
            TRANSFER)

}
}
}

#endif // MODEL_VISUALIZATION_OPERATIONTYPE_HPP
