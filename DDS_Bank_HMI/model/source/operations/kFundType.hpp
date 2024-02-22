#ifndef MODEL_OPERATIONS_KFUNDTYPE_H
#define MODEL_OPERATIONS_KFUNDTYPE_H

#include <enum.hpp>
#include <iostream>

namespace model
{
namespace operations
{

BETTER_ENUM(kFundType, int,
            Savings,
            Housing,
            None)

}  // namespace operations
}  // namespace model

#endif  // MODEL_OPERATIONS_KFUNDTYPE_H
