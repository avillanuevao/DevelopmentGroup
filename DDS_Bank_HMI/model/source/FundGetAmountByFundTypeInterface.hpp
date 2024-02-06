#ifndef FUNDGETAMOUNTBYFUNDTYPEINTERFACE_HPP
#define FUNDGETAMOUNTBYFUNDTYPEINTERFACE_HPP

#include <FundType.hpp>

namespace model
{

class FundGetAmountByFundTypeInterface
{
    public:
        FundGetAmountByFundTypeInterface() = default;

        virtual int getAmount(model::FundType fundType) const = 0;
};

}

#endif // FUNDGETAMOUNTBYFUNDTYPEINTERFACE_HPP
