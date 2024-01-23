#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include <FundType.hpp>

namespace model
{
namespace signal
{

class MoneyDepositedSignal
{
    public:
        MoneyDepositedSignal(model::FundType fundType, int amount);
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

#endif // SIGNAL_HPP
