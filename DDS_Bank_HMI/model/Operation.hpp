#ifndef OPERATION_HPP
#define OPERATION_HPP

#include <model/FundType.hpp>

namespace model
{

class Operation
{
    public:
        Operation(model::FundType fundTypeOrigin, model::FundType fundTypeDestination, int amount);

        model::FundType getFundTypeOrigin() const;
        void setFundTypeOrigin(model::FundType newFundTypeOrigin);

        model::FundType getFundTypeDestination() const;
        void setFundTypeDestination(model::FundType newFundTypeDestination);

        int getAmount() const;
        void setAmount(int newAmount);

private:
        model::FundType m_fundTypeOrigin;
        model::FundType m_fundTypeDestination;
        int m_amount;
};

}


#endif // OPERATION_HPP
