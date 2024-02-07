#ifndef MODEL_SIGNAL_UPDATEDFUNDSIGNAL_HPP
#define MODEL_SIGNAL_UPDATEDFUNDSIGNAL_HPP

#include <operations/FundType.hpp>

namespace  model
{
namespace operations
{
namespace signal
{

class UpdatedFundSignal
{
    public:
        UpdatedFundSignal(model::operations::FundType fundType, int amount);
        //Añadir variable miembro con la cantidad para que la vista pueda acceder al valor

        int getAmount() const;
        void setAmount(int newAmount);

        model::operations::FundType getFundType() const;
        void setFundType(model::operations::FundType newFundType);

private:
        model::operations::FundType m_fundType;
        int m_amount;
};

}
}
}

#endif // MODEL_SIGNAL_UPDATEDFUNDSIGNAL_HPP
