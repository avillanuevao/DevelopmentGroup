#ifndef MODEL_SIGNAL_UPDATEDFUNDSIGNAL_HPP
#define MODEL_SIGNAL_UPDATEDFUNDSIGNAL_HPP

#include <FundType.hpp>

namespace  model
{
namespace signal
{

class UpdatedFundSignal
{
    public:
        UpdatedFundSignal(model::FundType fundType, int amount);
        //Añadir variable miembro con la cantidad para que la vista pueda acceder al valor

        int getAmount() const;
        void setAmount(int newAmount);

        model::FundType getFundType() const;
        void setFundType(model::FundType newFundType);

private:
        model::FundType m_fundType;
        int m_amount;
};

}
}


#endif // MODEL_SIGNAL_UPDATEDFUNDSIGNAL_HPP
