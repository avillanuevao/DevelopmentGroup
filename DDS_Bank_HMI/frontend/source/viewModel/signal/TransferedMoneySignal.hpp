#ifndef FRONTEND_VIEWMODEL_SIGNAL_TRANSFEREDMONEYSIGNAL_HPP
#define FRONTEND_VIEWMODEL_SIGNAL_TRANSFEREDMONEYSIGNAL_HPP

#include <model/source/FundType.hpp>

namespace frontend
{
namespace viewModel
{
namespace signal
{

class TransferedMoneySignal
{
    public:
        TransferedMoneySignal(model::FundType originFundType, model::FundType destinationFundType, int amount);

        model::FundType getOriginFundType() const;
        void setOriginFundType(model::FundType newOriginFundType);

        model::FundType getDestinationFundType() const;
        void setDestinationFundType(model::FundType newDestinationFundType);

        int getAmount() const;
        void setAmount(int newAmount);

private:
        model::FundType m_originFundType;
        model::FundType m_destinationFundType;
        int m_amount;

};

}
}
}
#endif // FRONTEND_VIEWMODEL_SIGNAL_TRANSFEREDMONEYSIGNAL_HPP
