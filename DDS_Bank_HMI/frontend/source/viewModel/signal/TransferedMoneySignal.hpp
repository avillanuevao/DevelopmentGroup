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
        TransferedMoneySignal(model::FundType destinationFundType, int amount);

        model::FundType getDestinationFundType() const;
        int getAmount() const;

private:
        model::FundType m_destinationFundType;
        int m_amount;

};

}
}
}
#endif // FRONTEND_VIEWMODEL_SIGNAL_TRANSFEREDMONEYSIGNAL_HPP
