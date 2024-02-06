#ifndef MODEL_FUNDGETAMOUNTINTERFACE_HPP
#define MODEL_FUNDGETAMOUNTINTERFACE_HPP

#include <FundType.hpp>

namespace model
{

class FundGetAmountInterface
{
    public:
        FundGetAmountInterface() = default;

        virtual int getAmount() const = 0;
};

}

#endif // MODEL_FUNDGETAMOUNTINTERFACE_HPP
