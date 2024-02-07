#ifndef MODEL_FUNDDECREASEAMOUNTBYFUNDTYPEINTERFACE_HPP
#define MODEL_FUNDDECREASEAMOUNTBYFUNDTYPEINTERFACE_HPP

#include <operations/FundType.hpp>

namespace model
{
namespace operations
{

class FundDecreaseAmountByFundTypeInterface
{
    public:
        FundDecreaseAmountByFundTypeInterface() = default;

        virtual void decreaseAmount(model::operations::FundType fundType, int amount) = 0;
};

}
}

#endif // MODEL_FUNDDECREASEAMOUNTBYFUNDTYPEINTERFACE_HPP
