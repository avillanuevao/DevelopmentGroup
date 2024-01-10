#ifndef FUND_HPP
#define FUND_HPP

#include <model/FundType.hpp>

namespace model {

class Fund
{
    public:
        Fund(FundType fundType, int amount);

        void increaseAmount(int amount);

        FundType getFundType() const;
        int getAmount() const;
        void setAmount(int newAmount);

private:
        FundType m_fundType;
        int m_amount;
};

}

#endif // FUND_HPP
