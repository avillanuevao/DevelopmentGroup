#ifndef FUNDGETAMOUNTBYFUNDTYPEINTERFACE_HPP
#define FUNDGETAMOUNTBYFUNDTYPEINTERFACE_HPP

#include <operations/FundType.hpp>

namespace model
{
namespace operations
{

class FundGetAmountByFundTypeInterface
{
    public:
        FundGetAmountByFundTypeInterface() = default;

        virtual int getAmount(model::operations::FundType fundType) const = 0;
};

}
}

#endif // FUNDGETAMOUNTBYFUNDTYPEINTERFACE_HPP
