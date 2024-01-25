#ifndef MONEYDEPOSITEDSIGNAL_HPP
#define MONEYDEPOSITEDSIGNAL_HPP

#include <model/source/FundType.hpp>

namespace frontend
{
namespace viewModel
{
namespace signal
{

class MoneyDepositedSignal
{
    public:
        MoneyDepositedSignal(model::FundType fundType, int amount);



        model::FundType getFundType() const;
        void setFundType(model::FundType newFundType);

        int getAmount() const;
        void setAmount(int newAmount);

private:
        model::FundType m_fundType;
        int m_amount;
};

}
}
}
#endif // MONEYDEPOSITEDSIGNAL_HPP
