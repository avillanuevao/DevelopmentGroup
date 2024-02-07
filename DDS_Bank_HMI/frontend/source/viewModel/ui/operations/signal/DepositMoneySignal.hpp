#ifndef DEPOSITMONEYSIGNAL_HPP
#define DEPOSITMONEYSIGNAL_HPP

#include <model/source/operations/FundType.hpp>

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
#endif // DEPOSITMONEYSIGNAL_HPP
