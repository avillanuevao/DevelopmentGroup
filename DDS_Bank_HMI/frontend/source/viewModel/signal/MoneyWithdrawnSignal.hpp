#ifndef FRONTEND_VIEWMODEL_SIGNAL_MONEYWITHDRAWNSIGNAL_HPP
#define FRONTEND_VIEWMODEL_SIGNAL_MONEYWITHDRAWNSIGNAL_HPP

#include <model/source/FundType.hpp>

namespace frontend
{
namespace viewModel
{
namespace signal
{

class MoneyWithdrawnSignal
{
    public:
        MoneyWithdrawnSignal(model::FundType fundType, int amount);



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
#endif // FRONTEND_VIEWMODEL_SIGNAL_MONEYWITHDRAWNSIGNAL_HPP
