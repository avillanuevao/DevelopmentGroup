#ifndef MODEL_FUNDGETPARAMETERSINTERFACE_HPP
#define MODEL_FUNDGETPARAMETERSINTERFACE_HPP

#include <operations/FundType.hpp>

namespace model
{
namespace operations
{

class FundGetParametersInterface
{
    public:
        FundGetParametersInterface() = default;

        virtual int getAmount() const = 0;
        virtual model::operations::FundType getFundType() const = 0;
};

}
}

#endif // MODEL_FUNDGETPARAMETERSINTERFACE_HPP
