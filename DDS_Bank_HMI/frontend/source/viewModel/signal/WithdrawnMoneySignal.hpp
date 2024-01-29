#ifndef FRONTEND_VIEWMODEL_SIGNAL_WITHDRAWNMONEYSIGNAL_HPP
#define FRONTEND_VIEWMODEL_SIGNAL_WITHDRAWNMONEYSIGNAL_HPP

#include <model/source/FundType.hpp>

namespace frontend
{
namespace viewModel
{
namespace signal
{

class WithdrawnMoneySignal
{
    public:
        WithdrawnMoneySignal(model::FundType fundType,  int amount);

        model::FundType getFundType() const;
        int getAmount() const;

    private:
        model::FundType m_fundType;
        int m_amount;
};

}
}
}

#endif // FRONTEND_VIEWMODEL_SIGNAL_WITHDRAWNMONEYSIGNAL_HPP
