#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_DEPOSITMONEYSIGNAL_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_DEPOSITMONEYSIGNAL_HPP

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

class DepositMoneySignal
{
    public:
        DepositMoneySignal(int amount);

        int getAmount() const;

    private:
        int m_amount;

};

}
}
}
}
}
#endif // FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_DEPOSITMONEYSIGNAL_HPP
