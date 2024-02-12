#ifndef MODEL_OPERATIONS_FUNDTYPE_H
#define MODEL_OPERATIONS_FUNDTYPE_H

#include <iostream>
#include <enum.hpp>

namespace model
{
namespace operations
{

BETTER_ENUM(FundType, int,
            SAVINGS,
            HOUSING,
            NONE)

}
}

#endif // MODEL_OPERATIONS_FUNDTYPE_H
