#ifndef MODEL_FUNDSETFUNDTYPEINTERFACE_HPP
#define MODEL_FUNDSETFUNDTYPEINTERFACE_HPP

#include <FundType.hpp>

namespace model
{

class FundSetFundTypeInterface
{
    public:
        FundSetFundTypeInterface() = default;

        virtual void setFundType(model::FundType fundType) = 0;
};

}

#endif // MODEL_FUNDSETFUNDTYPEINTERFACE_HPP
