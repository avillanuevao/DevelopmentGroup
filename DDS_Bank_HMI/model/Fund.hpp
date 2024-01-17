#ifndef FUND_HPP
#define FUND_HPP

#include <model/FundType.hpp>

namespace model {

class Fund
{
    public:
        Fund(model::FundType fundType, int amount);

        void increaseAmount(int amount);

        model::FundType getFundType() const;
        int getAmount() const;
        void setAmount(int newAmount);

    private:
        model::FundType m_fundType;
        int m_amount;
};

}

#endif // FUND_HPP
