#ifndef FRONTEND_VIEWMODEL_SIGNAL_MONEYTRANSFEREDSIGNAL_HPP
#define FRONTEND_VIEWMODEL_SIGNAL_MONEYTRANSFEREDSIGNAL_HPP

#include <model/source/FundType.hpp>

namespace frontend
{
namespace viewModel
{
namespace signal
{

class MoneyTransferedSignal
{
    public:
        MoneyTransferedSignal(model::FundType fundType, int amount);

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
}



#endif // FRONTEND_VIEWMODEL_SIGNAL_MONEYTRANSFEREDSIGNAL_HPP
