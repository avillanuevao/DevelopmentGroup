#ifndef MODEL_FUNDGETPARAMETERINTERFACE_HPP
#define MODEL_FUNDGETPARAMETERINTERFACE_HPP

#include <FundType.hpp>

namespace model
{

class FundGetParameterInterface
{
    public:
        FundGetParameterInterface() = default;

        virtual int getAmount() const = 0;
        virtual model::FundType getFundType() const = 0;
};

}

#endif // MODEL_FUNDGETPARAMETERINTERFACE_HPP
