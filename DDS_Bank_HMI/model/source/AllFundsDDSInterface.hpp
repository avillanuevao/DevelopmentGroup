#ifndef ALLFUNDSDDSINTERFACE_HPP
#define ALLFUNDSDDSINTERFACE_HPP

#include <FundType.hpp>

namespace model
{

class AllFundsDDSInterface
{
    public:
        AllFundsDDSInterface() = default;

        virtual void setAmount(model::FundType fundType, int amount) = 0;
};

}

#endif // ALLFUNDSDDSINTERFACE_HPP
