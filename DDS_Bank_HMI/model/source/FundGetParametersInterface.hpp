#ifndef MODEL_FUNDGETPARAMETERSINTERFACE_HPP
#define MODEL_FUNDGETPARAMETERSINTERFACE_HPP

#include <FundType.hpp>

namespace model
{

class FundGetParametersInterface
{
    public:
        FundGetParametersInterface() = default;

        virtual int getAmount() const = 0;
        virtual model::FundType getFundType() const = 0;
};

}
#endif // MODEL_FUNDGETPARAMETERSINTERFACE_HPP
