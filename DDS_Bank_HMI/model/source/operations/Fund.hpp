#ifndef MODEL_OPERATIONS_FUND_HPP
#define MODEL_OPERATIONS_FUND_HPP

#include <stdexcept>

#include <operations/FundType.hpp>
#include <operations/FundInterface.hpp>

namespace model {
namespace operations
{

class Fund:
        public model::operations::FundInterface
{
    public:
        Fund(model::operations::FundType fundType, int amount);

        void increaseAmount(int amount) override;
        void decreaseAmount(int amount) override;

        int getAmount() const override;
        FundType getFundType() const override;
        void setAmount(int amount) override;
        void setFundType(FundType fundType) override;

    private:
        model::operations::FundType m_fundType;
        int m_amount;       
};

}
}

#endif // MODEL_OPERATIONS_FUND_HPP
