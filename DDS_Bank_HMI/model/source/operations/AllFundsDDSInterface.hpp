#ifndef ALLFUNDSDDSINTERFACE_HPP
#define ALLFUNDSDDSINTERFACE_HPP

#include <operations/FundType.hpp>

namespace model
{
namespace operations
{

class AllFundsDDSInterface
{
    public:
        AllFundsDDSInterface() = default;

        virtual void setAmount(model::operations::FundType fundType, int amount) = 0;
};

}
}
#endif // ALLFUNDSDDSINTERFACE_HPP
