#ifndef MODEL_OPERATIONS_FUNDSETPARAMETERSINTERFACE_HPP
#define MODEL_OPERATIONS_FUNDSETPARAMETERSINTERFACE_HPP

#include <operations/FundType.hpp>

namespace model
{
namespace operations
{

class FundSetParameterInterface
{
    public:
        FundSetParameterInterface() = default;

        virtual void setAmount(int amount) = 0;
        virtual void setFundType(model::operations::FundType fundType) = 0;
};

}
}

#endif // MODEL_OPERATIONS_FUNDSETAMOUNTBYFUNDTYPEINTERFACE_HPP