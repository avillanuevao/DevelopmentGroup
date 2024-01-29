#ifndef MODEL_SIGNAL_MONEYTRANSFEREDSIGNAL_HPP
#define MODEL_SIGNAL_MONEYTRANSFEREDSIGNAL_HPP

#include <FundType.hpp>

namespace  model
{
namespace  signal
{


class MoneyTransferedSignal
{
    public:
        MoneyTransferedSignal(model::FundType fundType,
                              int amount);


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
#endif // MODEL_SIGNAL_MONEYTRANSFEREDSIGNAL_HPP
