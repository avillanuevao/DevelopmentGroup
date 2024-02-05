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

        void increaseAmount(int amount) override;
        void decreaseAmount(int amount) override;

        int getAmount() const override;
        FundType getFundType() const;
        void setAmount(int amount) override;
        void setFundType(FundType fundType) override;

    private:
        model::FundType m_fundType;
        int m_amount;       
};

}

#endif // FUND_HPP
