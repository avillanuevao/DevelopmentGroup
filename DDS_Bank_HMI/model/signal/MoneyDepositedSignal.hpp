#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include <idl/bank.hpp>

namespace model
{
namespace signal
{

class MoneyDepositedSignal
{
    public:
        MoneyDepositedSignal(FundType fundType, int amount);
        //Añadir variable miembro con la cantidad para que la vista pueda acceder al valor

        int getAmount() const;
        void setAmount(int newAmount);

        FundType getFundType() const;
        void setFundType(FundType newFundType);

private:
        int m_amount;
        FundType m_fundType;
};

}
}

#endif // SIGNAL_HPP
