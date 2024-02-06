#ifndef MODEL_FUNDSETAMOUNTBYFUNDTYPEINTERFACE_HPP
#define MODEL_FUNDSETAMOUNTBYFUNDTYPEINTERFACE_HPP

#include <FundType.hpp>

namespace model
{

class FundSetAmountByFundTypeInterface
{
    public:
        FundSetAmountByFundTypeInterface() = default;

        virtual void setAmount(model::FundType fundType, int amount) = 0;
};

}

#endif // MODEL_FUNDSETAMOUNTBYFUNDTYPEINTERFACE_HPP
