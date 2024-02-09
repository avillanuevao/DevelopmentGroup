#ifndef MODEL_OPERATIONS_FUNDSETAMOUNTBYFUNDTYPEINTERFACE_HPP
#define MODEL_OPERATIONS_FUNDSETAMOUNTBYFUNDTYPEINTERFACE_HPP

#include <operations/FundType.hpp>

namespace model
{
namespace operations
{

class FundSetAmountByFundTypeInterface
{
    public:
        FundSetAmountByFundTypeInterface() = default;

        virtual void setAmount(model::operations::FundType fundType, int amount) = 0;
};

}
}

#endif // MODEL_OPERATIONS_FUNDSETAMOUNTBYFUNDTYPEINTERFACE_HPP
