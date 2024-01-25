#ifndef MODEL_SIGNAL_MONEYWITHDRAWNSIGNAL_HPP
#define MODEL_SIGNAL_MONEYWITHDRAWNSIGNAL_HPP

#include <FundType.hpp>

namespace model
{
namespace signal
{

class MoneyWithdrawnSignal
{
    public:
        MoneyWithdrawnSignal(model::FundType, int amount);

        int getAmount() const;
        void setAmount(int newAmount);

        model::FundType getFundType() const;
        void setFundType(model::FundType newFundType);

    private:
        model::FundType m_fundType;
        int m_amount;
};

}
}

#endif // MODEL_SIGNAL_MONEYWITHDRAWNSIGNAL_HPP
