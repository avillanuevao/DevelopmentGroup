#ifndef MODEL_FUNDSETPARAMETERSINTERFACE_HPP
#define MODEL_FUNDSETPARAMETERSINTERFACE_HPP

#include <FundType.hpp>

namespace model
{

class FundSetParameterInterface
{
    public:
        FundSetParameterInterface() = default;

        virtual void setAmount(int amount) = 0;
        virtual void setFundType(model::FundType fundType) = 0;
};

}

#endif // MODEL_FUNDSETPARAMETERSINTERFACE_HPP
