#ifndef FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_WITHDRAWNMONEYSIGNAL_HPP
#define FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_WITHDRAWNMONEYSIGNAL_HPP

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

class WithdrawnMoneySignal
{
    public:
        WithdrawnMoneySignal(int amount);

        int getAmount() const;

private:
        int m_amount;
};

}
}
}
}
}

#endif // FRONTEND_VIEWMODEL_UI_OPERATIONS_SIGNAL_WITHDRAWNMONEYSIGNAL_HPP
