#ifndef FUND_HPP
#define FUND_HPP

#include <stdexcept>

#include <FundType.hpp>
#include <FundInterface.hpp>

namespace model {
class Fund:
        public model::FundInterface
{
    public:
        Fund(model::FundType fundType, int amount);

        void increaseAmount(int amount) noexcept(false) override;
        void decreaseAmount(int amount) noexcept(false) override;

        model::FundType getFundType() const override;
        int getAmount() const override;
        void setAmount(int newAmount) noexcept(false) override;

    private:
        model::FundType m_fundType;
        int m_amount;
};

}

#endif // FUND_HPP
