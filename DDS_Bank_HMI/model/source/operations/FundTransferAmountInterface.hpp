#ifndef MODEL_OPERATIONS_FUNDTRANSFERAMOUNTINTERFACE_HPP
#define MODEL_OPERATIONS_FUNDTRANSFERAMOUNTINTERFACE_HPP

#include <operations/FundType.hpp>

namespace model
{
namespace operations
{

class FundTransferAmountInterface
{
    public:
        FundTransferAmountInterface() = default;

        virtual void transferAmount(model::operations::FundType fundTypeDestination, int amount) = 0;
};

}
}

#endif // MODEL_OPERATIONS_FUNDTRANSFERAMOUNTINTERFACE_HPP
