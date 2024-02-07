#ifndef MODEL_OPERATIONS_ALLFUNDSDDSINTERFACE_HPP
#define MODEL_OPERATIONS_ALLFUNDSDDSINTERFACE_HPP

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
#endif // MODEL_OPERATIONS_ALLFUNDSDDSINTERFACE_HPP
