#ifndef WITHDRAWNMONEYSIGNAL_HPP
#define WITHDRAWNMONEYSIGNAL_HPP

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

#endif // WITHDRAWNMONEYSIGNAL_HPP
