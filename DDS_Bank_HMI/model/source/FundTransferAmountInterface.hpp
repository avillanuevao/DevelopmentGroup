#ifndef MODEL_FUNDTRANSFERAMOUNTINTERFACE_HPP
#define MODEL_FUNDTRANSFERAMOUNTINTERFACE_HPP

#include <FundType.hpp>

namespace model
{

class FundTransferAmountInterface
{
    public:
        FundTransferAmountInterface() = default;

        virtual void transferAmount(model::FundType fundTypeDestination, int amount) = 0;
};

}

#endif // MODEL_FUNDTRANSFERAMOUNTINTERFACE_HPP
