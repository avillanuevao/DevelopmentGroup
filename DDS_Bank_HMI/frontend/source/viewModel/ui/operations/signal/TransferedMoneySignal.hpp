#ifndef FRONTEND_VIEWMODEL_SIGNAL_TRANSFEREDMONEYSIGNAL_HPP
#define FRONTEND_VIEWMODEL_SIGNAL_TRANSFEREDMONEYSIGNAL_HPP

#include <model/source/operations/kFundType.hpp>

namespace frontend
{
namespace viewModel
{
namespace ui
{
namespace operations
{
namespace signal
{

class TransferedMoneySignal
{
    public:
        TransferedMoneySignal(model::operations::kFundType destinationFundType, int amount);

        model::operations::kFundType getDestinationFundType() const;
        int getAmount() const;

private:
        model::operations::kFundType m_destinationFundType;
        int m_amount;

};

}
}
}
}
}

#endif // FRONTEND_VIEWMODEL_SIGNAL_TRANSFEREDMONEYSIGNAL_HPP
