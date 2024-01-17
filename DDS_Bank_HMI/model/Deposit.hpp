#ifndef DEPOSIT_HPP
#define DEPOSIT_HPP

#include <model/FundType.hpp>

namespace model
{

class Deposit
{
    public:
        Deposit(FundType fundType, int amount);

        FundType getFundType() const;
        void setFundType(FundType newFundType);

        int getAmount() const;
        void setAmount(int newAmount);

private:
        FundType m_fundType;
        int m_amount;
};

}


#endif // DEPOSIT_HPP
