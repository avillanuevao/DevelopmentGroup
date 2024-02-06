#ifndef MODEL_FUNDDECREASEAMOUNTBYFUNDTYPEINTERFACE_HPP
#define MODEL_FUNDDECREASEAMOUNTBYFUNDTYPEINTERFACE_HPP

#include <FundType.hpp>

namespace model
{

class FundDecreaseAmountByFundTypeInterface
{
    public:
        FundDecreaseAmountByFundTypeInterface() = default;

        virtual void decreaseAmount(model::FundType fundType, int amount) = 0;
};

}

#endif // MODEL_FUNDDECREASEAMOUNTBYFUNDTYPEINTERFACE_HPP
