#ifndef FUND_HPP
#define FUND_HPP

#include <stdexcept>

#include <FundType.hpp>

namespace model {
class Fund
{
    public:
        Fund(model::FundType fundType, int amount);

        void increaseAmount(int amount) noexcept(false);

        model::FundType getFundType() const;
        int getAmount() const;
        void setAmount(int newAmount) noexcept(false);

    private:
        model::FundType m_fundType;
        int m_amount;
};

}

#endif // FUND_HPP
